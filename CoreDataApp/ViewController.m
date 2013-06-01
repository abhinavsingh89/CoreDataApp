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

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    _managedObjectContext = [(AppDelegate*)[[UIApplication sharedApplication] delegate] managedObjectContext];
    
    EmployeeDetails* firstEntry = [NSEntityDescription insertNewObjectForEntityForName:@"EmployeeDetails" inManagedObjectContext:_managedObjectContext];
    
    firstEntry.name = @"Jason";
    firstEntry.employeeId = [NSNumber numberWithInt:1];
    firstEntry.employeeEmail = @"wngjason@gmail.com";

    NSError* err = nil;
    [_managedObjectContext save:&err];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
