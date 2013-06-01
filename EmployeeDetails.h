//
//  EmployeeDetails.h
//  CoreDataApp
//
//  Created by Abhinav Singh on 2013-06-01.
//  Copyright (c) 2013 eb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class EmployeePhones;

@interface EmployeeDetails : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * employeeId;
@property (nonatomic, retain) NSString * employeeEmail;
@property (nonatomic, retain) NSSet *employeePhones;
@end

@interface EmployeeDetails (CoreDataGeneratedAccessors)

- (void)addEmployeePhonesObject:(EmployeePhones *)value;
- (void)removeEmployeePhonesObject:(EmployeePhones *)value;
- (void)addEmployeePhones:(NSSet *)values;
- (void)removeEmployeePhones:(NSSet *)values;

@end
