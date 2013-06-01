//
//  ViewController.m
//  CoreDataApp
//
//  Created by Abhinav Singh on 2013-06-01.
//  Copyright (c) 2013 eb. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"
#import "EmployeeDetails.h"
#import "EmployeePhones.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSError* err = nil;
    
	// Do any additional setup after loading the view, typically from a nib.
    
    _managedObjectContext = [(AppDelegate*)[[UIApplication sharedApplication] delegate] managedObjectContext];
    
    EmployeeDetails* firstEntry = [NSEntityDescription insertNewObjectForEntityForName:@"EmployeeDetails" inManagedObjectContext:_managedObjectContext];
    
    firstEntry.name = @"Abhi3";
    firstEntry.employeeId = [NSNumber numberWithInt:3];
    firstEntry.employeeEmail = @"abhinavsingh89@gmail.com";
    
    EmployeePhones* employeePhone1 = [NSEntityDescription insertNewObjectForEntityForName:@"EmployeePhones" inManagedObjectContext:_managedObjectContext];

    employeePhone1.parentEmployee = firstEntry;
    employeePhone1.phoneNumber = @"123123123123";
    
    
    EmployeePhones* employeePhone2 = [NSEntityDescription insertNewObjectForEntityForName:@"EmployeePhones" inManagedObjectContext:_managedObjectContext];
    
    employeePhone2.parentEmployee = firstEntry;
    employeePhone2.phoneNumber = @"123123123123";

    
    [_managedObjectContext save:&err]; 
    
    NSFetchRequest* fetchReq = [[NSFetchRequest alloc] init];
    
    NSEntityDescription* entity = [NSEntityDescription entityForName:@"EmployeeDetails" inManagedObjectContext:_managedObjectContext];
    
    //NSPredicate* pred = [NSPredicate predicateWithFormat:@"employeeId = %d",3];
    
    [fetchReq setEntity:entity];
    //[fetchReq setPredicate:pred];

    NSArray* result = [_managedObjectContext executeFetchRequest:fetchReq error:&err];
    NSLog(@"%@", result);
    
    /*EmployeeDetails* objectInDB = [result objectAtIndex:0];
    NSLog(@"Name : %@", objectInDB.name );
    NSLog(@"ID : %d", [objectInDB.employeeId intValue]);
    NSLog(@"Email : %@", objectInDB.employeeEmail);*/
    
    for(EmployeeDetails* objectInDB in result)
    {
        NSLog(@"Name : %@", objectInDB.name );
        NSLog(@"ID : %d", [objectInDB.employeeId intValue]);
        NSLog(@"Email : %@", objectInDB.employeeEmail);
        for(EmployeePhones* phone in objectInDB.employeePhones)
        {
            NSLog(@"        Phone Number : %@",phone.phoneNumber);
        }
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
