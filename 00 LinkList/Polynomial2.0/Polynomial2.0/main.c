//
//  main.c
//  Polynomial2.0
//
//  Created by Kingsley on 2019/9/24.
//  Copyright © 2019 Kingsley. All rights reserved.
//

#include "Polynomial.h"

int main(int argc, const char * argv[]) {
    FILE *fp;
    Polynomial Pa, Pb;
    int m, n;
                                        
    m = 5;
    n = 6;
    
    
    printf("CreatPolyn 测试\n");            //函数CreatPolyn测试
    {
        printf("创建项数为 %d 的多项式Pa\n", m);
        fp=fopen("/Users/kingsley/Documents/Xcode Projects/Polynomial2.0/Polynomial2.0/TestData_Pa.txt", "r");    //文件指针，指向数据源
        if (fp == NULL){ //判断是否正常打开文件
            printf("读取文件失败\n");
            exit(0);
        }
        else{
            printf("读取文件成功\n");
        }
        CreatPolyn(fp, &Pa, m);
        fclose(fp);
        
        printf("创建项数为 %d 的多项式Pb\n", n);
        fp = fopen("/Users/kingsley/Documents/Xcode Projects/Polynomial2.0/Polynomial2.0/TestData_Pb.txt", "r");
        if (fp == NULL){ //判断是否正常打开文件
            printf("读取文件失败\n");
            exit(0);
        }
        else{
            printf("读取文件成功\n");
        }
        CreatPolyn(fp, &Pb, n);
        fclose(fp);
        printf("\n");
    }
        
    
    printf("PrintPolyn测试\n");            //函数PrintPolyn测试
    {
        printf("一元多项式 Pa = ");
        PrintPolyn(Pa);
        printf("\n");
        printf("一元多项式 Pb = ");
        PrintPolyn(Pb);
        printf("\n\n");
    }
    
    
    printf("PolynLength 测试\n");        //函数PolynLength测试
    {
        printf(" La 的项数为 %d ，Lb 的项数为 %d\n", PolynLength(Pa), PolynLength(Pb));
        printf("\n");
    }
        
    
    printf("AddPolyn测试\n");         //函数AddPolyn测试
    {
        AddPolyn(&Pa, &Pb);
        printf("Pa = Pa + Pb = ");
        PrintPolyn(Pa);
        printf("\n\n");
    }
    
    
    printf("DestroyPolyn_P测试\n");        //函数DestroyPolyn_P测试
    {
        printf("销毁 Pa 前：");
        (Pa.head && Pa.tail && Pa.len) ? printf(" Pa 存在！\n") : printf(" Pa 不存在！！\n");
        DestroyPolyn(&Pa);
        printf("销毁 Pa 后：");
        (Pa.head && Pa.tail && Pa.len) ? printf(" Pa 存在！\n") : printf(" Pa 不存在！！\n");
        printf("\n");
    }
    

    return 0;
}
