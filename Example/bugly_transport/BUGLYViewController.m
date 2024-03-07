//
//  BUGLYViewController.m
//  bugly_transport
//
//  Created by hodxiang on 03/07/2024.
//  Copyright (c) 2024 hodxiang. All rights reserved.
//

#import "BUGLYViewController.h"
#include "bugly_transport_test.h"

@interface BUGLYViewController ()

@end

@implementation BUGLYViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    
    test_bugly_transport();
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
