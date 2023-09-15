#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct inventory {
	int stock, style;
	struct info {
		int size, qty;
	} desc[12];
	float price;
} shoe[51];

int ans = 0, count = 0;

head() {
	printf("	  MASAYA SHOE INVENTORY TRACKING\n");
	printf("	Maligaya St., Fairview Quezon City\n\n");
}

input() {
	int a, b, y, ctr, size = 0;
	system("cls");
	head();
	printf("\t\t   NEW RECORD\n\n");
	for (a = count; a < 52; a++) {
		shoe[a].stock = count + 1;
		ctr = count + 1;
		printf("\tStock Number: %d", shoe[a].stock);
		printf("\n\tStyle Number (0 to 50): ");
		scanf("%d", &shoe[a].style);
		if (shoe[a].style < 0 || shoe[a].style > 50) {
			while (shoe[a].style < 0 || shoe[a].style > 50) {
        printf("\tStyle Number (0 to 50): ");
				scanf("%d", &shoe[a].style);
			}
		}
		printf("\tSize (3 to 14): ");
		scanf("%d", &size);
		if (size < 3 || size > 14) {
			do {
        printf("\tSize (3 to 14): ");
				scanf("%d", &size);
			} while (size < 3 || size > 14);
		}

		size -= 3;
		printf("\tQuantity: ");
		scanf("%d", &shoe[a].desc[size].qty);
		printf("\tPrice: ");
		scanf("%f", &shoe[a].price);
		count++;
		printf("\n\tPress any key to go back to main menu.");
		getch();
		main();
	}
}

validate() {
	int stock, style, a, x, y = 0;
	system("cls");
	head();
	printf("\t\t  DISPLAY RECORD\n\n");
	printf("\t1 - Stock Number\n\t2 - Style Number\n\t3 - Back to main menu\n\n\tAccess the record by: ");
	scanf("%d", &ans);
	switch (ans) {
		case 1:
			printf("\n\tStock Number: ");
			scanf("%d", &stock);
			while (stock < 1 || stock > count) {
        printf("\tRecord does not exist. Please try again.\n");
				printf("\tStock Number: ");
				scanf("%d", &stock);
      }
			x = stock - 1;
			break;
		case 2:
			while (y == 0) {
				printf("\n\tStyle Number: ");
				scanf("%d", &style);
				for (a = 0; a < count; a++)	{
					if (style == shoe[a].style)	{
            x = a;
						y = 1;
          }
				}
				if (y == 0)
					printf("\tRecord does not exist. Please try again.\n");
			}
			break;
		case 3:
			main();
		default:
			printf("\n\tChoose only from options 1 to 3.");
			getch();
			system("cls");
			validate();
	}
	return x;
}

display() {
	int x, a;
	x = validate();
	system("cls");
	head();
	printf("\t\t  DISPLAY RECORD\n\n");
	printf("\tStock Number: %d", shoe[x].stock);
	printf("\n\tStyle Number: %d", shoe[x].style);
	printf("\n\tPrice: %.2f", shoe[x].price);
	printf("\n\tSize\tQuantity");
	for (a = 0; a < 12; a++)
		printf("\n\t %2d\t   %3d", shoe[x].desc[a].size, shoe[x].desc[a].qty);
	printf("\n\n\tPress any key to go back to main menu.");
	getch();
	main();
}

update() {
	int x, ans, a, qty, size;
	float price;
	x = validate();
	system("cls");
	head();
	printf("\t\t  UPDATE RECORD\n\n");
	printf("\t1 - Price\n\t2 - Quantity\n\n\tUpdate the record by: ");
	scanf("%d", &ans);
	system("cls");
	switch(ans)	{
		case 1:
			head();
			printf("\t\t  UPDATE RECORD\n\n");
			printf("\tStock Number: %d", shoe[x].stock);
			printf("\n\tStyle Number: %d", shoe[x].style);
			printf("\n\tPrice: %.2f", shoe[x].price);
			printf("\n\n\tEnter new amount: ");
			scanf("%f", &price);
			shoe[x].price = price;
			printf("\n\tUpdated Price: %.2f", shoe[x].price);
			break;
		case 2:
			head();
			printf("\t\t  UPDATE RECORD\n\n");
			printf("\tStock Number: %d", shoe[x].stock);
			printf("\n\tStyle Number: %d", shoe[x].style);
			printf("\n\tSize\tQuantity");
			for (a = 0; a < 12; a++)
				printf("\n\t %2d\t   %3d", shoe[x].desc[a].size, shoe[x].desc[a].qty);
			while (size < 3 || size > 14)
			{
				printf("\n\n\tSize to be updated: ");
				scanf("%d", &size);
			}
			size -= 3;
			printf("\n\tEnter new quantity: ");
			scanf("%d", &qty);
			shoe[x].desc[size].qty = qty;
			printf("\n\tUpdated Quantity of Size %d: %d", size+3, shoe[x].desc[size].qty);
			break;
		default:
			printf("\n		Choose only from options 1 to 3.");
			getch();
			system("cls");
			update();
			break;
	}
	printf("\n\n\tPress any key to go back to main menu.");
	getch();
	main();
}

main() {
	int a, b;
	for (a = 0; a < 51; a++)
    	for (b = 0; b < 12; b++)
    		shoe[a].desc[b].size = 3 + b;
	system("cls");
	head();
	printf("\t\t    MAIN MENU\n\n");
	printf("\t1 - New Record\n");
	printf("\t2 - Display Record\n");
	printf("\t3 - Update Record\n");
	printf("\t4 - Exit\n");
	printf("\n\tWhat is your choice? ");
	scanf("%d", &ans);
	switch(ans)	{
		case 1:
			input();
			break;
		case 2:
			display();
			break;
		case 3:
			update();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\n		Choose only from options 1 to 4.");
			getch();
			system("cls");
			main();
			break;
	}
}
