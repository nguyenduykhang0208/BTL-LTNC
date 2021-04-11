#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct sach{
	char ten[30];
	char theloai[30];
	int giatien;
};

void nhap(sach*a){
	fflush(stdin);
	printf("nhap ten sach: ");
	gets(a->ten);
	printf("nhap the loai: ");
	gets(a->theloai);
	printf("nhap gia tien: ");
	scanf("%d", &a->giatien);
}

void xuat(sach*a){
	printf("%-20s %-10s %-10d\n",a->ten, a->theloai, a->giatien );
/*	printf("Ten: %s\n",a->ten);
	printf("The loai: %s \n", a->theloai);
	printf("Gia tien: %d \n", a->giatien);*/
}

void nhapds(sach*a, int &n){
	for(int i=0;i<n;i++){
		printf("Nhap quyen thu %d: \n", i);
		nhap(a+i);
	}
	
}

void hienthitheocot(){
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("%-20s %-10s %-10s \n", "Ten", "The loai", "Gia tien");
}

void xuatds(sach*a, int &n){
	hienthitheocot();
	for(int i=0;i<n;i++){
		xuat(a+i);
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
}

void sapxeptheoten(sach*a, int n){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=0 ; j<n ; j++){
			if(strcmp( (a->ten+i) , (a->ten+j) < 0 ) ){
				struct sach temp = *(a+j);
				*(a+j) = *(a+i);
				*(a+i) = temp;
			}
		}
	}
}

void timkiem(sach*a, int n){
	char tentheloai[30];
	int dem=0;
	printf("nhap ten the loai can tim: \n");
	scanf("%s", &tentheloai);
	for(int i=0; i<n; i++){
		if(strcmp(tentheloai,(a->theloai+i)) == 0){
			xuat((a+i));
			dem++;
		}
	}
	if(dem == 0){
		printf("Khong co sach can tim!\n");
	}
	else{
		printf("%s Co %d quyen sach \n",tentheloai, dem);
	} 
		
}

void ghifile( struct sach*a , int n ){
	getchar();
	char filename[30];
	printf("Nhap ten file: \n");
	gets(filename);
	FILE *fOut = fopen(filename , "a" );
	for(int i = 0 ; i < n ; i++ ){
		struct sach s = a[i];
		fprintf(fOut, "%-20s %-10s %-10s \n","Ten", "Theloai", "Gia tien" );
	}
	fclose(fOut);
}


void menu(){
	int chon,c=1;
	while(c){
		printf("*******MENU*******\n");
		printf("1.Nhap du lieu cua sach.\n");
		printf("2.Thong ke so sach.\n");
		printf("3.Tim kiem sach.\n");
		printf("4.Luu tap tin.\n");
		printf("5.Thoat\n");
		printf("Moi ban chon chuc nang: \n");
		scanf("%d", &chon);
		
	switch (chon){
		case 1:	int n;
				printf("nhap so sach: ");
				scanf("%d", &n);
				struct sach*a;
				a=(sach*)malloc(sizeof(sach));
				nhapds(a,n);
				break;
				
				
		case 2:
			xuatds(a,n);
			break;
			
			
		case 3: 
			timkiem(a,n);
			break;
			
			
		case 4:
			ghifile(a,n);
			break;
			
		case 5:
			c=0; 
			break;
			
		default :
			printf("Ban da chon sai, moi chon lai chuc nang.");
			break;
			
	}
}
	
}
int main(){
	menu();
}
