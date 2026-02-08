#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <limits>
#include <cmath>
#define debug(x) cout<<"!"<<" "<<x<<endl
using namespace std;

bool return_flag=0;//当前有没有尝试返回主菜单过

struct pet {
    char pet_number[20];
    char pet_name[20];
    char pet_type[20];
    char master_number[20];
    int raise_day_cnt;
    int price_per_day;
};

struct master {
    char master_number[20];
    char master_name[20];
    char contact_info[20];
    int pets_cnt;
};

struct PetNode {
	pet data;
	PetNode* next;
};

struct PetCostNode {
    pet data;
    PetCostNode* next;
};

struct MasterNode {
	master data;
	MasterNode* next;
};

struct MasterCost {
    master mst;
    PetCostNode* pets; // 从 vector<pet> 改为 PetCostNode* 链表
    int total_cost;    // 总开销
};

struct MasterCostNode {
    MasterCost data;
    MasterCostNode* next;
};


void ask_pet();
void ask_master();
void delete_pet();
void modify_pet();
void add_pet();
void sys_start();//主体
void initialize();//初始化
void setUTF8();//格式设置
void setcolor();//白色
void return_main();//返回主菜单
void clear_screen();//清屏
void sort_by_cost(); 
void save_data();
void free_pet_cost_list(PetCostNode* head);
void free_master_cost_list(MasterCostNode* head);
void free_pet_list(PetNode* head);
void free_master_list(MasterNode* head);
void getValidPetNumber(char pet_number[], int maxLength);
void getValidPetName(char pet_name[], int maxLength);
void safe_input_str(char* dest, int size, const char* prompt);
int main() {
	initialize();
    while (1) {
        sys_start();
    }
    return 0;
}

void sys_start(){
	return_flag=0;
	printf("请选择您要进行的操作（输入阿拉伯数字）\n1:宠物信息管理\n2:主人信息管理\n3:花销排序统计\n4:保存所有数据\n5:退出系统\n");
	int op;
    while (1) {
        if (scanf("%d", &op) != 1) {
            printf("输入数据无效，请输入数字！\n");
            while (getchar() != '\n'); // 清理输入缓冲区
            printf("请选择您要进行的操作（输入阿拉伯数字）\n1:宠物信息管理\n2:主人信息管理\n3:花销排序统计\n4:保存所有数据\n5:退出系统\n");
        }
        else if(op>5){
            printf("非法操作。\n");
        }
        else {
            break; 
        }
    }
	if (op == 1) ask_pet();
	else if (op == 2) ask_master();
	else if (op == 3) sort_by_cost();
	else if (op == 4) save_data();
	else if (op == 5) exit(1);
}

void clear_screen(){
	system("cls");
	return;
}
void setUTF8() {
	// 设置控制台输出为UTF-8编码
	SetConsoleOutputCP(CP_UTF8);
	// 设置控制台输入为UTF-8编码
	SetConsoleCP(CP_UTF8);
}

void initialize() {
	setUTF8();
	setcolor();
}
void setcolor(){
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	clear_screen();
	return;
}
void return_main(){
	if(return_flag) return;
	return_flag=1;
	printf("按任意键返回主菜单......\n");
	_getch();
	clear_screen();
	return;
}

void ask_pet() {
	clear_screen();
        printf("请选择您要进行的操作（输入阿拉伯数字）\n");
        printf("1:查询全部宠物信息\n");
        printf("2:查询某一宠物信息\n");
        printf("3:删除宠物信息\n");
        printf("4:修改宠物信息\n");
        printf("5:增加宠物信息\n");
        printf("6:返回主菜单\n");
        printf("请选择: ");
        
        int op;
		while (1) {
    		if (scanf("%d", &op) == 1) {
                while (getchar() != '\n');  // 清空多余回车
        	break;
    		}
			else {
        	printf("输入数据无效，请输入数字！\n");
        	while (getchar() != '\n'); // 清空输入缓冲区
    		}
		}
        clear_screen();
        switch (op) {
            case 1: {
                pet tmp;
                FILE* fp = fopen("pet.txt", "r");
                if (fp == NULL) {
                    printf("宠物文件不存在或无法打开！\n");
                    break;
                }
                
                bool isEmpty = true;
                while (fscanf(fp, "%s", &tmp.pet_number) != EOF) {
                    isEmpty = false;
                    fscanf(fp, "%s %s %s %d %d", &tmp.pet_name, &tmp.pet_type, 
                           &tmp.master_number, &tmp.raise_day_cnt, &tmp.price_per_day);
                    printf("宠物编号：%s\n宠物名称：%s\n宠物种类：%s\n主人编号：%s\n饲养天数：%d\n每日价格：%d\n\n",
                        tmp.pet_number, tmp.pet_name, tmp.pet_type, tmp.master_number, 
                        tmp.raise_day_cnt, tmp.price_per_day);
                }
                if (isEmpty) {
                    printf("没有宠物信息。\n");
                }
                fclose(fp);
                break;
            }
            
            case 2: {
                pet tmp;
                FILE* fp = fopen("pet.txt", "r");
                if (fp == NULL) {
                    printf("宠物文件不存在或无法打开！\n");
                    break;
                }
                
                printf("选择查询方式：\n1:按宠物编号查询\n2:按宠物姓名查询\n");
            char buf[64];
            int query_op;
            while (1) {
                if (fgets(buf, sizeof(buf), stdin) && sscanf(buf, "%d", &query_op) == 1) {
                    break;
                } else {
                    printf("输入数据无效，请输入数字！\n");
                }
            }

                if (query_op == 1) {
                    char pet_number[21];
                    getValidPetNumber(pet_number, 20);
                    bool found = false;
                    while (fscanf(fp, "%s", &tmp.pet_number) != EOF) {
                        fscanf(fp, "%s %s %s %d %d", &tmp.pet_name, &tmp.pet_type, 
                               &tmp.master_number, &tmp.raise_day_cnt, &tmp.price_per_day);
                        if (strcmp(tmp.pet_number, pet_number) == 0) {
                            found = true;
                            printf("宠物编号：%s\n宠物名称：%s\n宠物种类：%s\n主人编号：%s\n饲养天数：%d\n每日价格：%d\n\n",
                                tmp.pet_number, tmp.pet_name, tmp.pet_type, tmp.master_number, 
                                tmp.raise_day_cnt, tmp.price_per_day);
                            break;
                        }
                    }
                    if (!found) {
                        printf("未找到该宠物编号。\n");
                    }
                } 
                else if (query_op == 2) {
                    char pet_name[21];
                    getValidPetName(pet_name,20);
                    bool found = false;
                    while (fscanf(fp, "%s", &tmp.pet_number) != EOF) {
                        fscanf(fp, "%s %s %s %d %d", &tmp.pet_name, &tmp.pet_type, 
                               &tmp.master_number, &tmp.raise_day_cnt, &tmp.price_per_day);
                        if (strcmp(tmp.pet_name, pet_name) == 0) {
                            found = true;
                            printf("宠物编号：%s\n宠物名称：%s\n宠物种类：%s\n主人编号：%s\n饲养天数：%d\n每日价格：%d\n\n",
                                tmp.pet_number, tmp.pet_name, tmp.pet_type, tmp.master_number, 
                                tmp.raise_day_cnt, tmp.price_per_day);
                        }
                    }
                    if (!found) {
                        printf("未找到该宠物姓名。\n");
                    }
                } 
                else {
                    printf("无效的查询方式。\n");
                }
                fclose(fp);
                break;
            }
            
            case 3:
                delete_pet();
                break;
                
            case 4:
                modify_pet();
                break;
                
            case 5:
                add_pet();
                break;
                
            case 6:
                return_main();
				return;
            default:
                printf("无效的操作。\n");
                break;
        }
	return_main();
}

void ask_master() {
	clear_screen();
    FILE* fp = fopen("master.txt", "r");
    if (fp == NULL) {
        printf("主人文件不存在或无法打开！\n");
        return;
    }
    
    master tmp;
    bool isEmpty = true;
    while (fscanf(fp, "%s %s %s %d", &tmp.master_number, &tmp.master_name, 
                  &tmp.contact_info, &tmp.pets_cnt) != EOF) {
        isEmpty = false;
        printf("主人编号：%s\n主人姓名：%s\n联系方式：%s\n宠物数量：%d\n\n", 
               tmp.master_number, tmp.master_name, tmp.contact_info, tmp.pets_cnt);
    }
    if (isEmpty) {
        printf("没有主人信息。\n");
    }
    fclose(fp);
	return_main();
}

void delete_pet() {
	clear_screen();
	printf("=== 删除宠物信息 ===\n");
	printf("请选择删除方式：\n");
	printf("1:按宠物编号删除\n");
	printf("2:按宠物姓名删除\n");
	printf("请选择: ");
	
	int delete_op;
	while (1) {
    		if (scanf("%d", &delete_op) == 1) {
        	break;
    		}
			else {
        	printf("输入数据无效，请输入数字！\n");
        	while (getchar() != '\n'); // 清空输入缓冲区
    		}
		}
	char search_key[21];
	const int MAX_LENGTH = 20;
		
	if (delete_op == 1) {
    	getValidPetNumber(search_key, MAX_LENGTH);
	}else if (delete_op == 2) {
    	getValidPetName(search_key, MAX_LENGTH);
	} else {
    	printf("无效的选择。\n");
    	return;
	}
	PetNode* head = NULL;
	PetNode* tail = NULL;
	
	FILE* fp = fopen("pet.txt", "r");
	pet tmp;
	
	if (fp != NULL) {
		while (fscanf(fp, "%s %s %s %s %d %d",
					  tmp.pet_number, tmp.pet_name, tmp.pet_type,
					  tmp.master_number, &tmp.raise_day_cnt,
					  &tmp.price_per_day) != EOF) {
			PetNode* node = new PetNode;
			node->data = tmp;
			node->next = NULL;
			
			if (head == NULL)
				head = tail = node;
			else {
				tail->next = node;
				tail = node;
			}
		}
		fclose(fp);
	}
	
	bool found = false;
	char master_to_check[20] = "";
	
	for (PetNode* p = head; p != NULL; p = p->next) {
		if ((delete_op == 1 && strcmp(p->data.pet_number, search_key) == 0) ||
			(delete_op == 2 && strcmp(p->data.pet_name, search_key) == 0)) {
			found = true;
			strcpy(master_to_check, p->data.master_number);
			break;
		}
	}
	
	if (!found) {
		printf("未找到指定的宠物。\n");
		return;
	}
	
	PetNode* new_head = NULL;
	PetNode* new_tail = NULL;
	int deleted_cnt = 0;
	
	for (PetNode* p = head; p != NULL; ) {
		PetNode* next = p->next;
		
		if ((delete_op == 1 && strcmp(p->data.pet_number, search_key) == 0) ||
			(delete_op == 2 && strcmp(p->data.pet_name, search_key) == 0)) {
			printf("已删除宠物：%s（编号：%s）\n",
				   p->data.pet_name, p->data.pet_number);
			delete p;
			deleted_cnt++;
		} else {
			p->next = NULL;
			if (new_head == NULL)
				new_head = new_tail = p;
			else {
				new_tail->next = p;
				new_tail = p;
			}
		}
		p = next;
	}
	
	fp = fopen("pet.txt", "w");
	if (fp == NULL) {
		printf("无法打开宠物文件进行写入！\n");
		return;
	}
	
	for (PetNode* p = new_head; p != NULL; p = p->next) {
		fprintf(fp, "%s %s %s %s %d %d\n",
				p->data.pet_number, p->data.pet_name,
				p->data.pet_type, p->data.master_number,
				p->data.raise_day_cnt, p->data.price_per_day);
	}
	fclose(fp);
	
	int remaining_pets = 0;
	for (PetNode* p = new_head; p != NULL; p = p->next) {
		if (strcmp(p->data.master_number, master_to_check) == 0)
			remaining_pets++;
	}
	
	MasterNode* mhead = NULL;
	MasterNode* mtail = NULL;
	master mst;
	
	FILE* fp_master = fopen("master.txt", "r");
	if (fp_master != NULL) {
		while (fscanf(fp_master, "%s %s %s %d",
					  mst.master_number, mst.master_name,
					  mst.contact_info, &mst.pets_cnt) != EOF) {
			MasterNode* node = new MasterNode;
			node->data = mst;
			node->next = NULL;
			
			if (mhead == NULL)
				mhead = mtail = node;
			else {
				mtail->next = node;
				mtail = node;
			}
		}
		fclose(fp_master);
	}
	
	MasterNode* new_mhead = NULL;
	MasterNode* new_mtail = NULL;
	
	for (MasterNode* m = mhead; m != NULL; ) {
		MasterNode* next = m->next;
		
		if (strcmp(m->data.master_number, master_to_check) == 0) {
			if (remaining_pets == 0) {
				printf("主人 %s（编号：%s）没有其他宠物，已删除主人信息。\n",
					   m->data.master_name, m->data.master_number);
				delete m;
			} else {
				m->data.pets_cnt = remaining_pets;
				m->next = NULL;
				if (new_mhead == NULL)
					new_mhead = new_mtail = m;
				else {
					new_mtail->next = m;
					new_mtail = m;
				}
				printf("已更新主人 %s 的宠物数量为：%d\n",
					   m->data.master_name, remaining_pets);
			}
		} else {
			m->next = NULL;
			if (new_mhead == NULL)
				new_mhead = new_mtail = m;
			else {
				new_mtail->next = m;
				new_mtail = m;
			}
		}
		m = next;
	}
	
	fp_master = fopen("master.txt", "w");
	if (fp_master == NULL) {
		printf("无法打开主人文件进行写入！\n");
		return;
	}
	
	for (MasterNode* m = new_mhead; m != NULL; m = m->next) {
		fprintf(fp_master, "%s %s %s %d\n",
				m->data.master_number, m->data.master_name,
				m->data.contact_info, m->data.pets_cnt);
	}
	fclose(fp_master);
	
	printf("删除成功！共删除了 %d 条宠物记录。\n", deleted_cnt);
	return_main();
}

void modify_pet() {
	clear_screen();
	printf("=== 修改宠物信息 ===\n");
	printf("请输入待修改宠物的编号: ");
	
	char pet_number[21];
	getValidPetNumber(pet_number,20);
	
	PetNode* head = NULL;
	PetNode* tail = NULL;
	
	FILE* fp = fopen("pet.txt", "r");
	if (fp == NULL) {
		printf("宠物文件不存在或无法打开！\n");
		return;
	}
	
	pet tmp;
	bool found = false;
	
	while (fscanf(fp, "%s %s %s %s %d %d",
				  tmp.pet_number, tmp.pet_name, tmp.pet_type,
				  tmp.master_number, &tmp.raise_day_cnt,
				  &tmp.price_per_day) != EOF) {
		
		PetNode* node = new PetNode;
		node->data = tmp;
		node->next = NULL;
		
		if (head == NULL)
			head = tail = node;
		else {
			tail->next = node;
			tail = node;
		}
		
		if (strcmp(tmp.pet_number, pet_number) == 0)
			found = true;
	}
	fclose(fp);
	
	if (!found) {
		printf("该宠物编号不存在！\n");
		return;
	}
	
	printf("\n当前宠物信息：\n");
	for (PetNode* p = head; p != NULL; p = p->next) {
		if (strcmp(p->data.pet_number, pet_number) == 0) {
			printf("宠物编号：%s\n", p->data.pet_number);
			printf("宠物名称：%s\n", p->data.pet_name);
			printf("宠物种类：%s\n", p->data.pet_type);
			printf("主人编号：%s\n", p->data.master_number);
			printf("饲养天数：%d\n", p->data.raise_day_cnt);
			printf("每日价格：%d\n", p->data.price_per_day);
			break;
		}
	}
	
	printf("\n请选择要修改的内容：\n");
	printf("1:修改饲养天数\n");
	printf("2:修改每日价格\n");
	printf("3:修改所有信息\n");
	printf("请选择: ");
	
	int modify_op;
	while (1) {
    		if (scanf("%d", &modify_op) == 1) {
        	break;
    		}
			else {
        	printf("输入数据无效，请输入数字！\n");
        	while (getchar() != '\n'); // 清空输入缓冲区
    		}
		}
	
bool f = false;
    for (PetNode* p = head; p != NULL; p = p->next) {
        if (strcmp(p->data.pet_number, pet_number) == 0) {
            f = true;
            switch (modify_op) {
                case 1:
                    cout << "请输入新的饲养天数: ";
                    while (!(cin >> p->data.raise_day_cnt) || p->data.raise_day_cnt < 0) {
                        cout << "输入无效，请输入非负整数: ";
                        cin.clear();
                        cin.ignore(1024, '\n');
                    }
                    break;
                case 2:
                    cout << "请输入新的每日价格: ";
                    while (!(cin >> p->data.price_per_day) || p->data.price_per_day < 0) {
                        cout << "输入无效，请输入非负整数: ";
                        cin.clear();
                        cin.ignore(1024, '\n');
                    }
                    break;
                case 3:
                    safe_input_str(p->data.pet_name, sizeof(p->data.pet_name), "请输入新的宠物名称: ");
                    safe_input_str(p->data.pet_type, sizeof(p->data.pet_type), "请输入新的宠物种类: ");
                    safe_input_str(p->data.master_number, sizeof(p->data.master_number), "请输入新的主人编号: ");

                    cout << "请输入新的饲养天数: ";
                    while (!(cin >> p->data.raise_day_cnt) || p->data.raise_day_cnt < 0) {
                        cout << "输入无效，请输入非负整数: ";
                        cin.clear();
                        cin.ignore(1024, '\n');
                    }
                    cout << "请输入新的每日价格: ";
                    while (!(cin >> p->data.price_per_day) || p->data.price_per_day < 0) {
                        cout << "输入无效，请输入非负整数: ";
                        cin.clear();
                        cin.ignore(1024, '\n');
                    }
                    break;
                default:
                    cout << "无效的选择。\n";
                    return;
            }
            cout << "信息已成功更新。\n";
            break;
        }
    }
	
	fp = fopen("pet.txt", "w");
	if (fp == NULL) {
		printf("无法打开宠物文件进行写入！\n");
		return;
	}
	
	for (PetNode* p = head; p != NULL; p = p->next) {
		fprintf(fp, "%s %s %s %s %d %d\n",
				p->data.pet_number, p->data.pet_name,
				p->data.pet_type, p->data.master_number,
				p->data.raise_day_cnt, p->data.price_per_day);
	}
	fclose(fp);
	
	printf("宠物信息修改成功！\n");
	return_main();
}

void add_pet() {
	clear_screen();
	printf("=== 增加宠物信息 ===\n");
	
	pet new_pet;
    getValidPetNumber(new_pet.pet_number,20);
	
	FILE* fp = fopen("pet.txt", "r");
	if (fp != NULL) {
		pet tmp;
		while (fscanf(fp, "%s %s %s %s %d %d",
					  tmp.pet_number, tmp.pet_name, tmp.pet_type,
					  tmp.master_number, &tmp.raise_day_cnt,
					  &tmp.price_per_day) != EOF) {
			if (strcmp(tmp.pet_number, new_pet.pet_number) == 0) {
				fclose(fp);
				printf("该宠物编号已存在！\n");
				return;
			}
		}
		fclose(fp);
	}
	
	getValidPetName(new_pet.pet_name,20);
	char buffer[100];
    int c;
    while ((c = getchar()) != '\n' && c != EOF);//清理换行符
    while (1) {
        printf("请输入宠物种类: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';
        if (strlen(buffer) < 20) {
            strcpy(new_pet.pet_type, buffer);
            break;
        } else {
            printf("种类长度不能超过19个字符，请重新输入！\n");
        }
    }
    MasterNode* mhead = NULL;
	MasterNode* mtail = NULL;
	MasterNode* mnode;
	master tmp_master;

	//预读入
    FILE* fp_master = fopen("master.txt", "r");
    if (fp_master != NULL) {
        while (fscanf(fp_master, "%s %s %s %d",
                  tmp_master.master_number, tmp_master.master_name,
                  tmp_master.contact_info, &tmp_master.pets_cnt) != EOF) {
            mnode = new MasterNode;
            mnode->data = tmp_master;
            mnode->next = NULL;
            if (mhead == NULL)
                mhead = mtail = mnode;
            else {
                mtail->next = mnode;
                mtail = mnode;
            }
        }
        fclose(fp_master);
    }

    while (1) {
        printf("请输入主人编号: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';
        if (strlen(buffer) < 20) {
            strcpy(new_pet.master_number, buffer);
            break;
        } else {
            printf("编号长度不能超过19个字符，请重新输入！\n");
        }
    }
    while (1) {
        printf("请输入饲养天数: ");
        fgets(buffer, sizeof(buffer), stdin);
        int valid = 1;
        for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
            if (!isdigit(buffer[i])) {
                valid = 0;
                break;
            }
        }
        if (valid && strlen(buffer) > 1) {
            new_pet.raise_day_cnt = atoi(buffer);
            break;
        } else {
            printf("请输入有效的正整数天数！\n");
        }
    }
while (1) {
    printf("请输入每日价格: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("输入错误或文件结束！\n");
        break;
    }
    if (strchr(buffer, '\n') == NULL) { 
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("输入过长，请重新输入！\n");
        continue;
    }

    char *p = buffer;
    while (*p == ' ' || *p == '\t') p++;
    if (*p == '\n' || *p == '\0') { 
        printf("请输入有效的正数价格！\n");
        continue;
    }

    char *endptr;
    double price = strtod(p, &endptr);
    if (endptr == p) { 
        printf("请输入有效的正数价格！\n");
        continue;
    }
    if (price <= 0 || price > 1e19 || isnan(price) || isinf(price)) {
        printf("请输入合理的正数价格!\n");
        continue;
    }
    while (*endptr == ' ' || *endptr == '\t') endptr++;
    if (*endptr != '\n' && *endptr != '\0') {
        printf("请输入格式正确的正数价格！\n");
        continue;
    }
    break;
}
    bool master_exists = false;
    MasterNode* p = mhead;
    while (p != NULL) {
        if (strcmp(p->data.master_number, new_pet.master_number) == 0) {
            master_exists = true;
            break;
        }
        p = p->next;
    }

	
	if (!master_exists) {
		printf("\n主人文件中没有此宠物主人信息，请录入主人信息：\n");
    while (true) {
        cout << "请输入主人姓名: ";
        cin.getline(tmp_master.master_name, sizeof(tmp_master.master_name));
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入超出最大长度（" << sizeof(tmp_master.master_name) - 1 << "），请重新输入！" << endl;
            continue;
        }
        if (tmp_master.master_name[0] == '\0') {
            cout << "输入不能为空，请重新输入！" << endl;
            continue;
        }
        break; 
    }

    while (true) {
        cout << "请输入联系方式: ";
        cin.getline(tmp_master.contact_info, sizeof(tmp_master.contact_info));
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入超出最大长度（" << sizeof(tmp_master.contact_info) - 1 << "），请重新输入！" << endl;
            continue;
        }
        if (tmp_master.contact_info[0] == '\0') {
            cout << "输入不能为空，请重新输入！" << endl;
            continue;
        }
        break;
    }
		tmp_master.pets_cnt = 1;
		strcpy(tmp_master.master_number, new_pet.master_number);
		
		mnode = new MasterNode;
		mnode->data = tmp_master;
		mnode->next = NULL;
		if (mhead == NULL)
			mhead = mtail = mnode;
		else {
			mtail->next = mnode;
			mtail = mnode;
		}
		
		printf("主人信息已添加。\n");
	} else {
		for (MasterNode* p = mhead; p != NULL; p = p->next) {
			if (strcmp(p->data.master_number, new_pet.master_number) == 0) {
				p->data.pets_cnt++;
				break;
			}
		}
	}
	
	fp = fopen("pet.txt", "a");
	if (fp == NULL) {
		printf("无法打开宠物文件进行写入！\n");
		return;
	}
	fprintf(fp, "%s %s %s %s %d %d\n",
			new_pet.pet_number, new_pet.pet_name, new_pet.pet_type,
			new_pet.master_number, new_pet.raise_day_cnt, new_pet.price_per_day);
	fclose(fp);
	
	fp_master = fopen("master.txt", "w");
	if (fp_master == NULL) {
		printf("无法打开主人文件进行写入！\n");
		return;
	}
	for (MasterNode* p = mhead; p != NULL; p = p->next) {
		fprintf(fp_master, "%s %s %s %d\n",
				p->data.master_number, p->data.master_name,
				p->data.contact_info, p->data.pets_cnt);
	}
	fclose(fp_master);
	printf("宠物信息添加成功！\n");
	return_main();
}

void sort_by_cost() {
    clear_screen();
    printf("\n===按主人的宠物开销降序排列===\n");

    MasterCostNode* master_costs_head = NULL;

    FILE* fp_master = fopen("master.txt", "r");
    if (fp_master == NULL) {
        printf("主人文件不存在或无法打开！\n");
        return;
    }

    master tmp_master;
    while (fscanf(fp_master, "%s %s %s %d",
                  tmp_master.master_number, tmp_master.master_name,
                  tmp_master.contact_info, &tmp_master.pets_cnt) != EOF) {
        MasterCostNode* new_master_cost = (MasterCostNode*)malloc(sizeof(MasterCostNode));
        new_master_cost->data.mst = tmp_master;
        new_master_cost->data.pets = NULL;
        new_master_cost->data.total_cost = 0;
        new_master_cost->next = master_costs_head;
        master_costs_head = new_master_cost;

        FILE* fp_pet = fopen("pet.txt", "r");
        if (fp_pet != NULL) {
            pet tmp_pet;
            while (fscanf(fp_pet, "%s %s %s %s %d %d",
                          tmp_pet.pet_number, tmp_pet.pet_name, tmp_pet.pet_type,
                          tmp_pet.master_number, &tmp_pet.raise_day_cnt,
                          &tmp_pet.price_per_day) != EOF) {
                if (strcmp(tmp_pet.master_number, tmp_master.master_number) == 0) {
                    PetCostNode* new_pet = (PetCostNode*)malloc(sizeof(PetCostNode));
                    new_pet->data = tmp_pet;
                    new_pet->next = new_master_cost->data.pets;
                    new_master_cost->data.pets = new_pet;
                    new_master_cost->data.total_cost += tmp_pet.raise_day_cnt * tmp_pet.price_per_day;
                }
            }
            fclose(fp_pet);
        }
    }
    fclose(fp_master);

    for (MasterCostNode* i = master_costs_head; i != NULL; i = i->next) {
        for (MasterCostNode* j = i->next; j != NULL; j = j->next) {
            if (i->data.total_cost < j->data.total_cost) {
                MasterCost temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    for (MasterCostNode* current = master_costs_head; current != NULL; current = current->next) {
        printf("主人姓名：%s，联系方式：%s，总开销：%d\n",
               current->data.mst.master_name, current->data.mst.contact_info, current->data.total_cost);
        for (PetCostNode* pet_current = current->data.pets; pet_current != NULL; pet_current = pet_current->next) {
            printf("  宠物名称：%s，宠物编号：%s，宠物种类：%s，开销：%d\n",
                   pet_current->data.pet_name, pet_current->data.pet_number, pet_current->data.pet_type,
                   pet_current->data.raise_day_cnt * pet_current->data.price_per_day);
        }
        printf("\n");
    }


    free_master_cost_list(master_costs_head);
    return_main();
}

void save_data() {
    clear_screen();
    printf("=== 保存所有数据中 ===\n");

    PetNode* pets_head = NULL;
    MasterNode* masters_head = NULL;

    FILE* fp_pet = fopen("pet.txt", "r");
    if (fp_pet != NULL) {
        pet tmp_pet;
        while (fscanf(fp_pet, "%s %s %s %s %d %d",
                      tmp_pet.pet_number, tmp_pet.pet_name, tmp_pet.pet_type,
                      tmp_pet.master_number, &tmp_pet.raise_day_cnt, &tmp_pet.price_per_day) != EOF) {
            PetNode* new_pet = (PetNode*)malloc(sizeof(PetNode));
            new_pet->data = tmp_pet;
            new_pet->next = pets_head;
            pets_head = new_pet;
        }
        fclose(fp_pet);
    }

    FILE* fp_master = fopen("master.txt", "r");
    if (fp_master != NULL) {
        master tmp_master;
        while (fscanf(fp_master, "%s %s %s %d",
                      tmp_master.master_number, tmp_master.master_name,
                      tmp_master.contact_info, &tmp_master.pets_cnt) != EOF) {
            MasterNode* new_master = (MasterNode*)malloc(sizeof(MasterNode));
            new_master->data = tmp_master;
            new_master->next = masters_head;
            masters_head = new_master;
        }
        fclose(fp_master);
    }

    fp_pet = fopen("pet.txt", "w");
    if (fp_pet == NULL) {
        printf("宠物文件保存失败！\n");
        return_main();
        return;
    }
    for (PetNode* current = pets_head; current != NULL; current = current->next) {
        fprintf(fp_pet, "%s %s %s %s %d %d\n",
                current->data.pet_number, current->data.pet_name, current->data.pet_type,
                current->data.master_number, current->data.raise_day_cnt, current->data.price_per_day);
    }
    fclose(fp_pet);

    fp_master = fopen("master.txt", "w");
    if (fp_master == NULL) {
        printf("主人文件保存失败！\n");
        return_main();
        return;
    }
    for (MasterNode* current = masters_head; current != NULL; current = current->next) {
        fprintf(fp_master, "%s %s %s %d\n",
                current->data.master_number, current->data.master_name,
                current->data.contact_info, current->data.pets_cnt);
    }
    fclose(fp_master);

    printf("所有数据保存成功！\n");

    free_pet_list(pets_head);
    free_master_list(masters_head);
    return_main();
}

void free_pet_cost_list(PetCostNode* head) {
    while (head) {
        PetCostNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void free_master_cost_list(MasterCostNode* head) {
    while (head) {
        free_pet_cost_list(head->data.pets);
        MasterCostNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void free_pet_list(PetNode* head) {
    while (head) {
        PetNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void free_master_list(MasterNode* head) {
    while (head) {
        MasterNode* temp = head;
        head = head->next;
        free(temp);
    }
}


void getValidPetNumber(char pet_number[], int maxLength) {
    bool valid = false;

    while (!valid) {
        cout << "请输入宠物编号：" << endl;
        cin >> pet_number;

        if (strlen(pet_number) > maxLength) {
            cout << "输入编号长度过大，请重新输入！" << endl;
            continue;
        }

        bool all_digits = true;
        for (int i = 0; pet_number[i] != '\0'; ++i) {
            if (!isdigit(pet_number[i])) {
                all_digits = false;
                break;
            }
        }
        if (!all_digits) {
            cout << "输入编号必须为数字，请重新输入！" << endl;
            continue;
        }

        valid = true;
    }
}

void getValidPetName(char pet_name[], int maxLength) {
    bool valid = false;
    while (!valid) {
        cout << "请输入宠物名字：" << endl;
        cin >> pet_name;
        if (strlen(pet_name) > maxLength) {
            cout << "输入名字长度过大，请重新输入！" << endl;
            continue;
        }
        valid = true;
    }
}

void safe_input_str(char* dest, int size, const char* prompt) {
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.getline(dest, size);
}
