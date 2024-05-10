#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

	struct receipt
		{
			int it_no;
			float money;
			char name[20],email[20];
			char color[20],size[20],address[100], phone_no;
		};
			struct option{
				int item_no;
				int avail_no,sze;
				int amount,a;
				float price;
				char color[3][10],size[3][20],reg[12];
				struct option*next;	
			};
		void history(struct receipt*, FILE*);
		int n=3;
int main()
{		

		struct option stuff,stuff2;
		stuff.a=n;
		stuff2.a=1;
		struct receipt r;
		r.money=0;
		int choice,select,temp,product,item,i=0,sze=0;
		char username[20],password[25]="admin123",pass[25],read[10000],opt,customer_pass[25]="flopping";
		struct option *first,*ptr,*last, *sptr;
		FILE*fptr,*rptr;
				first=NULL;
				ptr=NULL;
				last=NULL;
				char choice1;
										
		
		printf("**----**----**----**----**----**----**----**----**----**----**----**----**----**\n 				NIA`s APPAREL\n**----**----**----**----**----**----**----**----**----**----**----**----**----**\n");
		printf("Select\n 1.Log in\t2.Guest mode\t3.Admin Log in");
		scanf("%d",&choice);
		
		
			////     CUSTOMER CONSOLE  //////
		if(choice==1 || choice==2){
			system("cls");
			printf("**----**----**----**----**----**----**----**----**----**----**----**----**----**\n 				NIA`s APPAREL\n**----**----**----**----**----**----**----**----**----**----**----**----**----**\n\n\n");
			if(choice==1){
			printf("Username: ");
			scanf("%s",&username);
			fflush(stdin);
			printf("Password:");
			scanf("%s",&pass);
			while((strcmp(customer_pass,pass))!=0){
					printf("Wrong Password\nRe-enter Password    ");
					scanf("%s",&pass);
			}
		}
					system("cls");
					printf("--------------------------------------------------------------------------------\n1.Home\t  2.Category\t3.Contact\t\n--------------------------------------------------------------------------------\n" );
					scanf("%d",&select);
						if(select==1){
									
										}
						else if(select==2){
							printf("\nSELECT CATEGORY\n____________________\n********************\n 1.WOMEN \n\n 2.MEN\n____________________\n********************");
							scanf("%d",&temp);
							if(temp==1 || temp==2){	
									rptr=fopen("receipt.bin","wb");
								do{	
										fptr=fopen("shirts.bin","rb");
									printf("\nCHOOSE PRODUCT\n 1.TOPS               2.JEANS");
									scanf("%d",&product);
									if(product==1){
										system("cls");
											while(fread(&stuff,sizeof(struct option),1,fptr)){
										if(fptr!=NULL){
												printf("***********************\nShirt #%d\n",stuff.item_no);
												printf("sr.no:%s\n",stuff.reg);
												printf("\nColors: ");
												for(i=0;i<stuff.amount;i++){
												printf("%s, ",stuff.color[i]);
												}
												//printf("Number of sizes available[MAX-3]");
												//scanf("%d",&sze);
												printf("\nSizes:  ");
												for(i=0;i<stuff.sze;i++){
														printf("%s,",stuff.size[i]);
												}
												printf("\nAvailable amount: %d",stuff.avail_no);
												printf("\nPrice:%.1f\n",stuff.price);
												printf("***********************\n");
											}
					}

						fclose(fptr);
						fptr=fopen("shirts.bin","rb");
						printf("Select Item\n Enter the Shirt#");
						scanf("%d",&r.it_no);
						fflush(stdin);
						while(fread(&stuff.item_no,sizeof(struct option),1,fptr)){
						if(stuff.item_no==r.it_no){
							r.money+=stuff.price;
							stuff.avail_no--;}
						}
						printf("Enter Size[S,M,L]");
						scanf("%s",&r.size);
						printf("Enter Color");
						scanf("%s",&r.color);
					fwrite(&r,sizeof(struct receipt),1,rptr);
							
									
						
					printf("************ ADDED TO CART SUCCESSFULLY  ************\n");
					printf("Do you want to add another item to cart?(Y/N)");
					opt=tolower(getche());
								}
					system("cls");
				}while(opt=='y');
					fclose(rptr);
				
				system("cls");
				fflush(stdin);
				printf("ENTER SHIPPMENT DETAILS");
				printf("Email:\n ");
				fgets(r.email,sizeof(r.email),stdin);
				fflush(stdin);
				printf("\nPhone Number: ");
				scanf("%s",&r.phone_no);
				fflush(stdin);
				printf("Address: ");
				fgets(r.address,sizeof(r.address),stdin);
				fflush(stdin);
				system("cls");
				printf("**********************************************\n                    RECEIPT\n**********************************************\n ");
				rptr=fopen("receipt.bin","rb");
					if(rptr!=NULL){
							system("cls");
									
								while(fread(&r,sizeof(struct receipt),1,rptr)){
									printf("***********************\nShirt #%d\n",r.it_no);
									printf("\nColors: ");
									puts(r.color);
										
									printf("\nSizes:  ");
									puts(r.size);
									printf("***********************\n");
											}
									printf("\nPrice:%.1f\n",r.money);
									fclose(rptr);	
									}
									
				
				}
				else if(product==2){
						system("cls");
										while(fread(&stuff2,sizeof(struct option),1,fptr)){
										if(fptr!=NULL){
												printf("***********************\nJeans #%d\n",stuff2.item_no);
												printf("sr.no:%s\n",stuff2.reg);
												printf("\nColors: ");
												for(i=0;i<stuff2.amount;i++){
												printf("%s, ",stuff2.color[i]);
												}
												//printf("Number of sizes available[MAX-3]");
												//scanf("%d",&sze);
												printf("\nSizes:  ");
												for(i=0;i<stuff2.sze;i++){
														printf("%s,",stuff2.size[i]);
												}
												printf("\nAvailable amount: %d",stuff2.avail_no);
												printf("\nPrice:%.1f\n",stuff2.price);
												printf("***********************\n");
											}
					}

						fclose(fptr);
						fptr=fopen("jeans.bin","rb");
						printf("Select Item\n Enter the Jeans#");
						scanf("%d",&r.it_no);
						fflush(stdin);
						while(fread(&stuff2.item_no,sizeof(struct option),1,fptr)){
						if(stuff2.item_no==r.it_no){
							r.money+=stuff2.price;
							stuff2.avail_no--;}
						}
						printf("Enter Size[S,M,L]");
						scanf("%s",&r.size);
						printf("Enter Color");
						scanf("%s",&r.color);
					fwrite(&r,sizeof(struct receipt),1,rptr);
							
									
						
					printf("************ ADDED TO CART SUCCESSFULLY  ************\n");
					printf("Do you want to add another item to cart?(Y/N)");
					opt=tolower(getche());
								}
					system("cls");
				}while(opt=='y');
					fclose(rptr);
				
				system("cls");
				fflush(stdin);
				printf("ENTER SHIPPMENT DETAILS");
				printf("Email:\n ");
				fgets(r.email,sizeof(r.email),stdin);
				fflush(stdin);
				printf("\nPhone Number: ");
				scanf("%s",&r.phone_no);
				fflush(stdin);
				printf("Address: ");
				fgets(r.address,sizeof(r.address),stdin);
				
				fflush(stdin);
				system("cls");
				printf("**********************************************\n                    RECEIPT\n**********************************************\n ");
				rptr=fopen("receipt.bin","rb");
					if(rptr!=NULL){
					
								while(fread(&r,sizeof(struct receipt),1,rptr)){
									printf("***********************\nJeans #%d\n",r.it_no);
									printf("\nColors: ");
									puts(r.color);
										
									printf("\nSize:  ");
									puts(r.size);
									printf("***********************\n");
											}
									printf("\nPrice:%.1f\n",r.money);
									fclose(rptr);	
									}
				
					
			
			else{
				printf("WRONG SELECTION");
			}
	
}
		///ADMIN CONSOLE//

		else if(choice==3){

			system("cls");		
			printf("**----**----**----**----**----**----**----**----**----**----**----**----**----**\n 				NIA`s APPAREL\n**----**----**----**----**----**----**----**----**----**----**----**----**----**\n\n\n");
			printf("Username: ");
			scanf("%s",&username);
			fflush(stdin);
			printf("Password:");
			scanf("%s",&pass);
			while((strcmp(password,pass))!=0){
					printf("Wrong Password\nRe-enter Password    ");
					scanf("%s",&pass);
				}
			
			printf("--------------------------------------------------------------------------------\n1.Check History\t  2.Add Items\t3.Check Item Details\t\n--------------------------------------------------------------------------------\n" );
				scanf("%d",&select);	
			switch(select){
				case 1:
					fflush(stdin);
					system("cls");
					printf("________________________________________________________________________________________________________\n                                             HISTORY\n_______________________________________________________________________________________________________\n\n");
				rptr=fopen("receipt.bin","rb");
					if(rptr!=NULL){
							
								while(fread(&r,sizeof(struct receipt),1,rptr)){
									printf("***********************\nShirt #%d\n",r.it_no);
									printf("\nColors: ");
									puts(r.color);
										
									printf("\nSizes:  ");
									puts(r.size);
									printf("***********************\n");
											}
									printf("\nPrice:%.1f\n",r.money);
									fclose(rptr);	
									}
					break;
					
				case 2:
					printf("\nCHOOSE PRODUCT\n 1.TOPS               2.JEANS");
					scanf("%d",&product);
					if(product==1){
					fptr=fopen("shirts.bin","ab");
					if(fptr!=NULL){
//										fptr=fopen("shirts.bin","ab");
										
									do{
										fflush(stdin);
										stuff.item_no=stuff.a;
										printf("\nEnter the serial number of item #%d  ",stuff.a);
										fgets(stuff.reg,sizeof(stuff.reg),stdin);
										fflush(stdin);
										printf("Enter the price  ");
										scanf("%f",&stuff.price);
										fflush(stdin);
										printf("Enter number of colors available (MAX-3)  ");
										scanf("%d",&stuff.amount);
										fflush(stdin);
										printf("Enter colors available");
										for(i=0;i<stuff.amount;i++){
										scanf("%s",&stuff.color[i]);
													}
										fflush(stdin);
										printf("Enter the number of items available  ");
										scanf("%d",&stuff.avail_no);
										fflush(stdin);
										printf("Enter number of sizes available[MAX 3]");
										scanf("%d",&stuff.sze);
										printf("Enter sizes Available [S,M,L]\n");
										for(i=0;i<stuff.sze;i++){
										scanf("%s",&stuff.size[i]);
										fflush(stdin);
													}
													n=stuff.a++;
									
									fwrite(&stuff,sizeof(struct option),1,fptr);
//									fwrite(&a,sizeof(a),1,fptr);								
									printf("Do you want to add other items(Y/N)");
									choice=tolower(getche());
								}while(choice=='y'||choice=='Y');
								break;
								fclose(fptr);
							}
					}
					else if(product==2){
										fptr=fopen("jeans.bin","wb");
					if(fptr!=NULL){
										
									do{
										fflush(stdin);
										stuff2.item_no=stuff2.a;
										printf("\nEnter the serial number of item #%d  ",stuff2.a);
										fgets(stuff2.reg,sizeof(stuff.reg),stdin);
										fflush(stdin);
										printf("Enter the price  ");
										scanf("%f",&stuff2.price);
										fflush(stdin);
										printf("Enter number of colors available (MAX-3)  ");
										scanf("%d",&stuff2.amount);
										fflush(stdin);
										printf("Enter colors available");
										for(i=0;i<stuff2.amount;i++){
										scanf("%s",&stuff2.color[i]);
													}
										fflush(stdin);
										printf("Enter the number of items available  ");
										scanf("%d",&stuff2.avail_no);
										fflush(stdin);
										printf("Enter number of sizes available[MAX 3]");
										scanf("%d",&stuff2.sze);
										fflush(stdin);
										printf("Enter sizes Available [S,M,L]\n");
										for(i=0;i<stuff2.sze;i++){
										scanf("%s",&stuff2.size[i]);
										fflush(stdin);
													}
													n=stuff2.a++;
									
									fwrite(&stuff2,sizeof(struct option),1,fptr);
//									fwrite(&a,sizeof(a),1,fptr);								
									printf("Do you want to add other items(Y/N)");
									choice=tolower(getche());
								}while(choice=='y'||choice=='Y');
								break;
								fclose(fptr);
							}
					}
					break;
					case 3:
							
								printf("\nCHOOSE PRODUCT\n 1.TOPS               2.JEANS");
									scanf("%d",&product);
								if(product==1){
										system("cls");
											printf("________________________________________________________________________________________________________\n                                             ITEM DETAILS\n_______________________________________________________________________________________________________\n\n");
											while(fread(&stuff,sizeof(struct option),1,fptr)){
										if(fptr!=NULL){
												printf("***********************\nShirt #%d\n",stuff.item_no);
												printf("sr.no:%s\n",stuff.reg);
												printf("\nColors: ");
												for(i=0;i<stuff.amount;i++){
												printf("%s, ",stuff.color[i]);
												}
											//	printf("Number of sizes available[MAX-3]");
											//	scanf("%d",&sze);
												printf("\nSizes:  ");
												for(i=0;i<stuff.sze;i++){
														printf("%s,",stuff.size[i]);
												}
												printf("\nAvailable amount: %d",stuff.avail_no);
												printf("\nPrice:%.1f\n",stuff.price);
												printf("***********************\n");
											}
										}
								}
					else if(product==2){
							system("cls");
																		printf("________________________________________________________________________________________________________\n                                             ITEM DETAILS\n_______________________________________________________________________________________________________\n\n");
										while(fread(&stuff2,sizeof(struct option),1,fptr)){
										if(fptr!=NULL){
												printf("***********************\nJeans #%d\n",stuff2.item_no);
												printf("sr.no:%s\n",stuff2.reg);
												printf("\nColors: ");
												for(i=0;i<stuff2.amount;i++){
												printf("%s, ",stuff2.color[i]);
												}
											//	printf("Number of sizes available[MAX-3]");
											//	scanf("%d",&sze);
												printf("\nSizes:  ");
												for(i=0;i<stuff2.sze;i++){
														printf("%s,",stuff2.size[i]);
												}
												printf("\nAvailable amount: %d",stuff2.avail_no);
												printf("\nPrice:%.1f\n",stuff2.price);
												printf("***********************\n");
											}
								}
							}
					
					else{
						printf("WRONG SELECTION");
					
					}
						break;
					default:
					printf("Wrong Selection");
					
			}
			
	
				}
		else{
			printf("Wrong Selection");
		}
		
		
		
		return 0;
}

