//
//  RandViewController.m
//  ChatDemo-NonUI
//
//  Created by dujiepeng on 14-5-3.
//  Copyright (c) 2014年 djp. All rights reserved.
//

#import "RandViewController.h"
#import "RandViewController+Login.h"
#import "RandViewController+Register.h"
#import "EaseMob.h"

@interface RandViewController ()

@property (weak, nonatomic) IBOutlet UIButton *randButton;
@property (weak, nonatomic) IBOutlet UIButton *loginButton;

@end

@implementation RandViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    if ([UIDevice currentDevice].systemVersion.floatValue >= 7.0) {
        self.edgesForExtendedLayout = UIRectEdgeNone;
    }
    
    [self setupButton:_randButton];
    [self setupButton:_loginButton];

    [_randButton addTarget:self
                    action:@selector(randButtonPressed:)
          forControlEvents:UIControlEventTouchUpInside];

    [_loginButton addTarget:self
                    action:@selector(loginBtnPressed:)
          forControlEvents:UIControlEventTouchUpInside];
}

-(void)setupButton:(UIButton *)btn{
    btn.layer.borderColor = [UIColor blackColor].CGColor;
    btn.layer.borderWidth = 0.5;
    btn.clipsToBounds = YES;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(void)randButtonPressed:(UIButton *)sender{
    // 随机生成用户名
    [self registerRandUsername];
}

-(void)loginBtnPressed:(UIButton *)sender{
    [self login];
}
@end
