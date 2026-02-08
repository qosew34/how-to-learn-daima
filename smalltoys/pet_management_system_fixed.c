#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 定义结构体
// 宠物信息结构体
typedef struct Pet {
    char petId[20];          // 宠物编号
    char petName[50];        // 宠物名字
    char petBreed[50];       // 宠物品种
    char ownerId[20];        // 主人编号
    int fosterDays;          // 寄养天数
    float dailyPrice;        // 每日价格
    struct Pet* next;        // 指向下一个宠物的指针
} Pet;

// 主人信息结构体
typedef struct Owner {
    char ownerId[20];        // 主人编号
    char ownerName[50];      // 主人姓名
    char contact[20];        // 联系方式
    int petCount;            // 寄养宠物数量
    struct Owner* next;      // 指向下一个主人的指针
} Owner;

// 全局变量，链表头指针
Pet* petHead = NULL;
Owner* ownerHead = NULL;

// 函数声明
void initMenu();
void loadData();
void saveData();
void queryPet();
void deletePet();
void modifyPet();
void addPet();
void sortByCost();
void displayAllPets();
void displayAllOwners();
Pet* findPetById(char* id);
Pet* findPetByName(char* name);
Owner* findOwnerById(char* id);
void deleteOwnerIfNoPets(char* ownerId);
float calculateTotalCost(Pet* pet);

// 主函数
int main() {
    initMenu();
    return 0;
}

// 初始化菜单
void initMenu() {
    int choice;
    
    // 加载数据
    loadData();
    
    while (1) {
        system("cls"); // 清屏
        printf("========================================\n");
        printf("        宠物寄养管理系统\n");
        printf("========================================\n");
        printf("1. 查询宠物信息\n");
        printf("2. 删除宠物信息\n");
        printf("3. 修改宠物信息\n");
        printf("4. 添加宠物信息\n");
        printf("5. 按花销排序\n");
        printf("6. 显示所有宠物\n");
        printf("7. 显示所有主人\n");
        printf("8. 保存数据\n");
        printf("0. 退出系统\n");
        printf("========================================\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);
        getchar(); // 吸收换行符
        
        switch (choice) {
            case 1:
                queryPet();
                break;
            case 2:
                deletePet();
                break;
            case 3:
                modifyPet();
                break;
            case 4:
                addPet();
                break;
            case 5:
                sortByCost();
                break;
            case 6:
                displayAllPets();
                break;
            case 7:
                displayAllOwners();
                break;
            case 8:
                saveData();
                break;
            case 0:
                printf("退出系统前是否保存数据？(y/n): ");
                char saveChoice;
                scanf(" %c", &saveChoice);
                if (saveChoice == 'y' || saveChoice == 'Y') {
                    saveData();
                }
                printf("感谢使用宠物寄养管理系统！\n");
                return;
            default:
                printf("无效的选择，请重新输入！\n");
        }
        printf("\n按任意键返回主菜单...");
        getchar();
    }
}

// 加载数据
void loadData() {
    FILE* petFile = fopen("pets.txt", "r");
    if (petFile != NULL) {
        char line[200];
        while (fgets(line, sizeof(line), petFile) != NULL) {
            Pet* newPet = (Pet*)malloc(sizeof(Pet));
            sscanf(line, "%s %s %s %s %d %f", 
                   newPet->petId, newPet->petName, newPet->petBreed, 
                   newPet->ownerId, &newPet->fosterDays, &newPet->dailyPrice);
            newPet->next = petHead;
            petHead = newPet;
        }
        fclose(petFile);
    }
    
    FILE* ownerFile = fopen("owners.txt", "r");
    if (ownerFile != NULL) {
        char line[200];
        while (fgets(line, sizeof(line), ownerFile) != NULL) {
            Owner* newOwner = (Owner*)malloc(sizeof(Owner));
            sscanf(line, "%s %s %s %d", 
                   newOwner->ownerId, newOwner->ownerName, newOwner->contact, 
                   &newOwner->petCount);
            newOwner->next = ownerHead;
            ownerHead = newOwner;
        }
        fclose(ownerFile);
    }
}

// 保存数据
void saveData() {
    FILE* petFile = fopen("pets.txt", "w");
    if (petFile == NULL) {
        printf("保存宠物数据失败！\n");
        return;
    }
    
    Pet* currentPet = petHead;
    while (currentPet != NULL) {
        fprintf(petFile, "%s %s %s %s %d %.2f\n", 
                currentPet->petId, currentPet->petName, currentPet->petBreed, 
                currentPet->ownerId, currentPet->fosterDays, currentPet->dailyPrice);
        currentPet = currentPet->next;
    }
    fclose(petFile);
    
    FILE* ownerFile = fopen("owners.txt", "w");
    if (ownerFile == NULL) {
        printf("保存主人数据失败！\n");
        return;
    }
    
    Owner* currentOwner = ownerHead;
    while (currentOwner != NULL) {
        fprintf(ownerFile, "%s %s %s %d\n", 
                currentOwner->ownerId, currentOwner->ownerName, currentOwner->contact, 
                currentOwner->petCount);
        currentOwner = currentOwner->next;
    }
    fclose(ownerFile);
    
    printf("数据保存成功！\n");
}

// 查找宠物 by ID
Pet* findPetById(char* id) {
    Pet* current = petHead;
    while (current != NULL) {
        if (strcmp(current->petId, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 查找宠物 by 名字
Pet* findPetByName(char* name) {
    Pet* current = petHead;
    while (current != NULL) {
        if (strstr(current->petName, name) != NULL) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 查找主人 by ID
Owner* findOwnerById(char* id) {
    Owner* current = ownerHead;
    while (current != NULL) {
        if (strcmp(current->ownerId, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 显示所有宠物
void displayAllPets() {
    system("cls");
    printf("========================================\n");
    printf("            所有宠物信息\n");
    printf("========================================\n");
    printf("宠物编号  宠物名字    宠物品种    主人编号  寄养天数  每日价格\n");
    printf("----------------------------------------\n");
    
    Pet* current = petHead;
    if (current == NULL) {
        printf("没有宠物信息！\n");
        return;
    }
    
    while (current != NULL) {
        printf("%-10s %-12s %-12s %-10s %-8d %.2f\n", 
               current->petId, current->petName, current->petBreed, 
               current->ownerId, current->fosterDays, current->dailyPrice);
        current = current->next;
    }
}

// 显示所有主人
void displayAllOwners() {
    system("cls");
    printf("========================================\n");
    printf("            所有主人信息\n");
    printf("========================================\n");
    printf("主人编号  主人姓名    联系方式    宠物数量\n");
    printf("----------------------------------------\n");
    
    Owner* current = ownerHead;
    if (current == NULL) {
        printf("没有主人信息！\n");
        return;
    }
    
    while (current != NULL) {
        printf("%-10s %-12s %-12s %-8d\n", 
               current->ownerId, current->ownerName, current->contact, 
               current->petCount);
        current = current->next;
    }
}

// 查询宠物信息
void queryPet() {
    system("cls");
    printf("========================================\n");
    printf("            查询宠物信息\n");
    printf("========================================\n");
    printf("1. 按宠物编号查询\n");
    printf("2. 按宠物名字模糊查询\n");
    printf("3. 返回主菜单\n");
    printf("请输入您的选择: ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // 吸收换行符
    
    switch (choice) {
        case 1: {
            char petId[20];
            printf("请输入宠物编号: ");
            fgets(petId, sizeof(petId), stdin);
            petId[strcspn(petId, "\n")] = '\0'; // 移除换行符
            
            Pet* pet = findPetById(petId);
            if (pet != NULL) {
                Owner* owner = findOwnerById(pet->ownerId);
                printf("\n宠物信息查询结果:\n");
                printf("----------------------------------------\n");
                printf("宠物编号: %s\n", pet->petId);
                printf("宠物名字: %s\n", pet->petName);
                printf("宠物品种: %s\n", pet->petBreed);
                printf("寄养天数: %d\n", pet->fosterDays);
                printf("每日价格: %.2f\n", pet->dailyPrice);
                printf("总花销: %.2f\n", pet->fosterDays * pet->dailyPrice);
                if (owner != NULL) {
                    printf("\n主人信息:\n");
                    printf("主人编号: %s\n", owner->ownerId);
                    printf("主人姓名: %s\n", owner->ownerName);
                    printf("联系方式: %s\n", owner->contact);
                    printf("寄养宠物数量: %d\n", owner->petCount);
                }
            } else {
                printf("没有找到该宠物！\n");
            }
            break;
        }
        case 2: {
            char petName[50];
            printf("请输入宠物名字: ");
            fgets(petName, sizeof(petName), stdin);
            petName[strcspn(petName, "\n")] = '\0'; // 移除换行符
            
            printf("\n宠物信息查询结果:\n");
            printf("----------------------------------------\n");
            printf("宠物编号  宠物名字    宠物品种    主人编号  寄养天数  每日价格\n");
            printf("----------------------------------------\n");
            
            Pet* current = petHead;
            bool found = false;
            while (current != NULL) {
                if (strstr(current->petName, petName) != NULL) {
                    printf("%-10s %-12s %-12s %-10s %-8d %.2f\n", 
                           current->petId, current->petName, current->petBreed, 
                           current->ownerId, current->fosterDays, current->dailyPrice);
                    found = true;
                }
                current = current->next;
            }
            
            if (!found) {
                printf("没有找到匹配的宠物！\n");
            }
            break;
        }
        case 3:
            return;
        default:
            printf("无效的选择！\n");
    }
}

// 删除宠物
void deletePet() {
    system("cls");
    printf("========================================\n");
    printf("            删除宠物信息\n");
    printf("========================================\n");
    printf("1. 按宠物编号删除\n");
    printf("2. 按宠物名字删除\n");
    printf("3. 返回主菜单\n");
    printf("请输入您的选择: ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // 吸收换行符
    
    switch (choice) {
        case 1: {
            char petId[20];
            printf("请输入要删除的宠物编号: ");
            fgets(petId, sizeof(petId), stdin);
            petId[strcspn(petId, "\n")] = '\0'; // 移除换行符
            
            Pet* current = petHead;
            Pet* prev = NULL;
            while (current != NULL) {
                if (strcmp(current->petId, petId) == 0) {
                    printf("确定要删除以下宠物信息吗？(y/n)\n");
                    printf("宠物编号: %s, 宠物名字: %s, 宠物品种: %s\n", 
                           current->petId, current->petName, current->petBreed);
                    
                    char confirm;
                    scanf(" %c", &confirm);
                    if (confirm == 'y' || confirm == 'Y') {
                        // 更新主人的宠物数量
                        Owner* owner = findOwnerById(current->ownerId);
                        if (owner != NULL) {
                            owner->petCount--;
                            // 如果主人没有宠物了，删除主人信息
                            if (owner->petCount == 0) {
                                // 删除主人信息
                                Owner* ownerCurrent = ownerHead;
                                Owner* ownerPrev = NULL;
                                while (ownerCurrent != NULL) {
                                    if (strcmp(ownerCurrent->ownerId, current->ownerId) == 0) {
                                        if (ownerPrev == NULL) {
                                            ownerHead = ownerCurrent->next;
                                        } else {
                                            ownerPrev->next = ownerCurrent->next;
                                        }
                                        free(ownerCurrent);
                                        break;
                                    }
                                    ownerPrev = ownerCurrent;
                                    ownerCurrent = ownerCurrent->next;
                                }
                            }
                        }
                        
                        // 删除宠物信息
                        if (prev == NULL) {
                            petHead = current->next;
                        } else {
                            prev->next = current->next;
                        }
                        free(current);
                        printf("宠物信息删除成功！\n");
                    } else {
                        printf("取消删除操作！\n");
                    }
                    return;
                }
                prev = current;
                current = current->next;
            }
            printf("没有找到该宠物！\n");
            break;
        }
        case 2: {
            char petName[50];
            printf("请输入要删除的宠物名字: ");
            fgets(petName, sizeof(petName), stdin);
            petName[strcspn(petName, "\n")] = '\0'; // 移除换行符
            
            Pet* current = petHead;
            Pet* prev = NULL;
            bool found = false;
            
            while (current != NULL) {
                if (strcmp(current->petName, petName) == 0) {
                    found = true;
                    printf("确定要删除以下宠物信息吗？(y/n)\n");
                    printf("宠物编号: %s, 宠物名字: %s, 宠物品种: %s\n", 
                           current->petId, current->petName, current->petBreed);
                    
                    char confirm;
                    scanf(" %c", &confirm);
                    if (confirm == 'y' || confirm == 'Y') {
                        // 更新主人的宠物数量
                        Owner* owner = findOwnerById(current->ownerId);
                        if (owner != NULL) {
                            owner->petCount--;
                            // 如果主人没有宠物了，删除主人信息
                            if (owner->petCount == 0) {
                                // 删除主人信息
                                Owner* ownerCurrent = ownerHead;
                                Owner* ownerPrev = NULL;
                                while (ownerCurrent != NULL) {
                                    if (strcmp(ownerCurrent->ownerId, current->ownerId) == 0) {
                                        if (ownerPrev == NULL) {
                                            ownerHead = ownerCurrent->next;
                                        } else {
                                            ownerPrev->next = ownerCurrent->next;
                                        }
                                        free(ownerCurrent);
                                        break;
                                    }
                                    ownerPrev = ownerCurrent;
                                    ownerCurrent = ownerCurrent->next;
                                }
                            }
                        }
                        
                        // 删除宠物信息
                        Pet* temp = current;
                        if (prev == NULL) {
                            petHead = current->next;
                            current = petHead;
                        } else {
                            prev->next = current->next;
                            current = current->next;
                        }
                        free(temp);
                        printf("宠物信息删除成功！\n");
                        continue;
                    }
                }
                prev = current;
                current = current->next;
            }
            
            if (!found) {
                printf("没有找到该宠物！\n");
            }
            break;
        }
        case 3:
            return;
        default:
            printf("无效的选择！\n");
    }
}

// 修改宠物信息
void modifyPet() {
    system("cls");
    printf("========================================\n");
    printf("            修改宠物信息\n");
    printf("========================================\n");
    
    char petId[20];
    printf("请输入要修改的宠物编号: ");
    fgets(petId, sizeof(petId), stdin);
    petId[strcspn(petId, "\n")] = '\0'; // 移除换行符
    
    Pet* pet = findPetById(petId);
    if (pet == NULL) {
        printf("没有找到该宠物！\n");
        return;
    }
    
    printf("\n当前宠物信息:\n");
    printf("宠物编号: %s\n", pet->petId);
    printf("宠物名字: %s\n", pet->petName);
    printf("宠物品种: %s\n", pet->petBreed);
    printf("寄养天数: %d\n", pet->fosterDays);
    printf("每日价格: %.2f\n", pet->dailyPrice);
    
    printf("\n请选择要修改的字段:\n");
    printf("1. 寄养天数\n");
    printf("2. 每日价格\n");
    printf("3. 返回主菜单\n");
    printf("请输入您的选择: ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // 吸收换行符
    
    switch (choice) {
        case 1: {
            int newDays;
            printf("请输入新的寄养天数: ");
            scanf("%d", &newDays);
            printf("确定要将寄养天数从 %d 修改为 %d 吗？(y/n): ", pet->fosterDays, newDays);
            
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                pet->fosterDays = newDays;
                printf("寄养天数修改成功！\n");
            } else {
                printf("取消修改操作！\n");
            }
            break;
        }
        case 2: {
            float newPrice;
            printf("请输入新的每日价格: ");
            scanf("%f", &newPrice);
            printf("确定要将每日价格从 %.2f 修改为 %.2f 吗？(y/n): ", pet->dailyPrice, newPrice);
            
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                pet->dailyPrice = newPrice;
                printf("每日价格修改成功！\n");
            } else {
                printf("取消修改操作！\n");
            }
            break;
        }
        case 3:
            return;
        default:
            printf("无效的选择！\n");
    }
}

// 添加宠物信息
void addPet() {
    system("cls");
    printf("========================================\n");
    printf("            添加宠物信息\n");
    printf("========================================\n");
    
    Pet* newPet = (Pet*)malloc(sizeof(Pet));
    
    // 输入宠物信息
    printf("请输入宠物编号: ");
    fgets(newPet->petId, sizeof(newPet->petId), stdin);
    newPet->petId[strcspn(newPet->petId, "\n")] = '\0'; // 移除换行符
    
    // 检查宠物编号是否已存在
    if (findPetById(newPet->petId) != NULL) {
        printf("宠物编号已存在！\n");
        free(newPet);
        return;
    }
    
    printf("请输入宠物名字: ");
    fgets(newPet->petName, sizeof(newPet->petName), stdin);
    newPet->petName[strcspn(newPet->petName, "\n")] = '\0'; // 移除换行符
    
    printf("请输入宠物品种: ");
    fgets(newPet->petBreed, sizeof(newPet->petBreed), stdin);
    newPet->petBreed[strcspn(newPet->petBreed, "\n")] = '\0'; // 移除换行符
    
    printf("请输入主人编号: ");
    fgets(newPet->ownerId, sizeof(newPet->ownerId), stdin);
    newPet->ownerId[strcspn(newPet->ownerId, "\n")] = '\0'; // 移除换行符
    
    printf("请输入寄养天数: ");
    scanf("%d", &newPet->fosterDays);
    
    printf("请输入每日价格: ");
    scanf("%f", &newPet->dailyPrice);
    getchar(); // 吸收换行符
    
    // 检查主人是否存在
    Owner* owner = findOwnerById(newPet->ownerId);
    if (owner == NULL) {
        printf("\n该主人不存在，是否添加主人信息？(y/n): ");
        char addOwnerChoice;
        scanf(" %c", &addOwnerChoice);
        getchar(); // 吸收换行符
        
        if (addOwnerChoice == 'y' || addOwnerChoice == 'Y') {
            Owner* newOwner = (Owner*)malloc(sizeof(Owner));
            strcpy(newOwner->ownerId, newPet->ownerId);
            
            printf("请输入主人姓名: ");
            fgets(newOwner->ownerName, sizeof(newOwner->ownerName), stdin);
            newOwner->ownerName[strcspn(newOwner->ownerName, "\n")] = '\0'; // 移除换行符
            
            printf("请输入联系方式: ");
            fgets(newOwner->contact, sizeof(newOwner->contact), stdin);
            newOwner->contact[strcspn(newOwner->contact, "\n")] = '\0'; // 移除换行符
            
            newOwner->petCount = 1;
            newOwner->next = ownerHead;
            ownerHead = newOwner;
        } else {
            printf("取消添加宠物信息！\n");
            free(newPet);
            return;
        }
    } else {
        // 更新主人的宠物数量
        owner->petCount++;
    }
    
    // 添加宠物到链表
    newPet->next = petHead;
    petHead = newPet;
    
    printf("宠物信息添加成功！\n");
}

// 计算总花销
float calculateTotalCost(Pet* pet) {
    return pet->fosterDays * pet->dailyPrice;
}

// 按主人总花销排序
void sortByCost() {
    system("cls");
    printf("========================================\n");
    printf("            按主人总花销排序\n");
    printf("========================================\n");
    
    // 创建主人花销数组
    int ownerCount = 0;
    Owner* currentOwner = ownerHead;
    while (currentOwner != NULL) {
        ownerCount++;
        currentOwner = currentOwner->next;
    }
    
    if (ownerCount == 0) {
        printf("没有主人信息！\n");
        return;
    }
    
    // 分配内存存储主人和总花销信息
    typedef struct {
        Owner* owner;
        float totalCost;
    } OwnerCost;
    
    OwnerCost* ownerCosts = (OwnerCost*)malloc(ownerCount * sizeof(OwnerCost));
    
    // 计算每个主人的总花销
    int index = 0;
    currentOwner = ownerHead;
    while (currentOwner != NULL) {
        ownerCosts[index].owner = currentOwner;
        
        // 计算该主人的所有宠物总花销
        float total = 0;
        Pet* currentPet = petHead;
        while (currentPet != NULL) {
            if (strcmp(currentPet->ownerId, currentOwner->ownerId) == 0) {
                total += calculateTotalCost(currentPet);
            }
            currentPet = currentPet->next;
        }
        
        ownerCosts[index].totalCost = total;
        index++;
        currentOwner = currentOwner->next;
    }
    
    // 冒泡排序，按总花销从高到低
    for (int i = 0; i < ownerCount - 1; i++) {
        for (int j = 0; j < ownerCount - i - 1; j++) {
            if (ownerCosts[j].totalCost < ownerCosts[j+1].totalCost) {
                OwnerCost temp = ownerCosts[j];
                ownerCosts[j] = ownerCosts[j+1];
                ownerCosts[j+1] = temp;
            }
        }
    }
    
    // 显示排序结果
    printf("\n排序结果（总花销从高到低）:\n");
    printf("========================================\n");
    
    for (int i = 0; i < ownerCount; i++) {
        Owner* owner = ownerCosts[i].owner;
        float totalCost = ownerCosts[i].totalCost;
        
        printf("\n主人编号: %s\n", owner->ownerId);
        printf("主人姓名: %s\n", owner->ownerName);
        printf("联系方式: %s\n", owner->contact);
        printf("总花销: %.2f\n", totalCost);
        printf("寄养宠物:\n");
        
        Pet* currentPet = petHead;
        while (currentPet != NULL) {
            if (strcmp(currentPet->ownerId, owner->ownerId) == 0) {
                printf("  - 宠物名字: %s, 品种: %s, 寄养天数: %d, 每日价格: %.2f\n", 
                       currentPet->petName, currentPet->petBreed, 
                       currentPet->fosterDays, currentPet->dailyPrice);
            }
            currentPet = currentPet->next;
        }
        printf("----------------------------------------\n");
    }
    
    free(ownerCosts);
}
