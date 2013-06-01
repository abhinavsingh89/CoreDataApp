//
//  EmployeeDetails.h
//  CoreDataApp
//
//  Created by Abhinav Singh on 2013-06-01.
//  Copyright (c) 2013 eb. All rights reserved.
//

#import <CoreData/CoreData.h>

@interface EmployeeDetails : NSManagedObject

@property (nonatomic, strong) NSNumber* employeeId;
@property (nonatomic, strong) NSString* employeeEmail;
@property (nonatomic, strong) NSString* name;

@end
