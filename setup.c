/*
 * populate_accounts.c
 * Copyright (C) 2020 ayushyadav99 <ayushyadav99@ayushyadav99-VirtualBox>
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "structs.h"


int main(){


    // ----------------------------------------------------------------------------------------------
    //  Adding Accounts to the .dat file
    // ----------------------------------------------------------------------------------------------
    int fd = open("Accounts.dat", O_CREAT | O_RDWR, 0777);
    if (fd == -1){
        printf("unable to create and open file\n");
        exit(1);
    }
    lseek(fd, 0, SEEK_SET);

    Account acco1 = {
        .id = 1,
        .balance = 179000,
    };

    write(fd, &acco1, sizeof(acco1));

    Account acco2 = {
        .id = 2,
        .balance = 50500,
    };

    write(fd, &acco2, sizeof(acco2));
    
    Account acco3 = {
        .id = 3,
        .balance = 42000,
    };

    write(fd, &acco3, sizeof(acco3));
    
    Account acco4 = {
        .id = 4,
        .balance = 97436,
    };

    write(fd, &acco4, sizeof(acco4));
    close(fd);
    // ----------------------------------------------------------------------------------------------
    //  Adding Admins to the .dat file
    // ----------------------------------------------------------------------------------------------
    int fd1 = open("Admins.dat", O_CREAT | O_RDWR, 0777);
    if (fd1 == -1){
        printf("unable to create and open file\n");
        exit(1);
    }
    lseek(fd1, 0, SEEK_SET);

    AdminCredentials User1 = {
        .username = "admin1",
        .password = "admin531",
    };

    write(fd1, &User1, sizeof(User1));

    AdminCredentials User2 = {
        .username = "admin2",
        .password = "admin135",
    };
    write(fd1, &User2, sizeof(User2));
    close(fd1);


    // ----------------------------------------------------------------------------------------------
    //  Adding Users to the .dat file
    // ----------------------------------------------------------------------------------------------
    int fd2 = open("Users.dat", O_CREAT | O_RDWR, 0777);
    if (fd2 == -1){
        printf("unable to create and open file\n");
        exit(1);
    }
    lseek(fd2, 0, SEEK_SET);

    User user1 = {
        .id = 1,
        .password = "saketh531",
        .account_type = singleAccount,
        .account_id = 1,
    };

    write(fd2, &user1, sizeof(user1));

    User user2 = {
        .id = 2,
        .password = "saketh532",
        .account_type = singleAccount,
        .account_id = 2,
    };

    write(fd2, &user2, sizeof(user2));
    
    User user3 = {
        .id = 3,
        .password = "saketh533",
        .account_type = singleAccount,
        .account_id = 3,
    };

    write(fd2, &user3, sizeof(user3));
    
    User user4 = {
        .id = 4,
        .password = "saketh534",
        .account_type = singleAccount,
        .account_id = 4,
    };

    write(fd2, &user4, sizeof(user4));
    close(fd2);

}


