//
//  EmployeePhones.h
//  CoreDataApp
//
//  Created by Abhinav Singh on 2013-06-01.
//  Copyright (c) 2013 eb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class EmployeeDetails;

@interface EmployeePhones : NSManagedObject

@property (nonatomic, retain) NSString * phoneNumber;
@property (nonatomic, retain) EmployeeDetails *parentEmployee;

@end
