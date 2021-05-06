#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct date{
	int ngay;
	int thang;
	int nam;
};

struct khachhang{
	char tenkh[30];
	int sdt;
};

struct hanghoa{
	char ten[30];
	int id;
	int dongia;
	int soluong;
	struct date* Date;
	struct khachhang* Kh;
};

void nhaptenKH(struct khachhang* a){
	printf("Ten khach hang: ");
	gets(a->tenkh);
	printf("SDT: ");
	scanf("%d",&a->sdt);
}

void nhapngaymua(struct date* b){
	printf("Ngay: ");
	scanf("%d", &b->ngay);
	printf("Thang: ");
	scanf("%d", &b->thang);
	printf("Nam: ");
	scanf("%d", &b->nam);
}

void nhap(struct hanghoa* c){
	printf("ID: ");
	scanf("%d", &c->id);
	fflush(stdin);
	printf("Ten hang hoa: ");
	gets(c->ten);
	printf("So luong: ");
	scanf("%d", &c->soluong);
	printf("Don gia: ");
	scanf("%d", &c->dongia);
	c->Kh=( struct khachhang* )malloc(sizeof(struct khachhang));
	fflush(stdin);
	nhaptenKH(c->Kh);
	c->Date=(struct date*)malloc(sizeof(struct date));
	nhapngaymua(c->Date);
}

void xuat(struct hanghoa* c){
	printf("%-10d %-20s %-10d %-20d %-7d/%-7d/%-7d %-20s %-20d\n",c->id, c->ten, c->soluong, c->dongia, 
	c->Date->ngay, c->Date->thang, c->Date->nam, c->Kh->tenkh, c->Kh->sdt );
}

void hienthidanhsach(){
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("%-10s %-20s %-10s %-20s %-21s %-20s %-20s\n","ID","Mat hang","So luong","Don gia","Ngay mua","Ten KH","SDT");
}


void nhapds(struct hanghoa* HangHoa, int n){
	for(int i=0;i<n;i++){
		nhap(HangHoa+i);
	}
}

void xuatds(struct hanghoa* HangHoa, int n){
	hienthidanhsach();
	for(int i=0;i<n;i++){
		xuat(HangHoa+i);
	}
		printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
}

void timkiemtheoten(struct hanghoa*HangHoa, int n){
	char tenkhachhang[30];
	printf("\nNhap ten khach hang can tim: ");
	gets(tenkhachhang);
	int dem=0;
	for(int i=0;i<n;i++){
		if(strcmp( tenkhachhang , ((HangHoa+i)->Kh->tenkh ) ) == 0){
			xuat(HangHoa+i);
			dem=1;
		}
	}
	if(dem == 0 ){
		printf("\nKhong co ten %s trong danh sach\n", tenkhachhang);
	}
	
}

void sapxeptheoten(struct hanghoa*HangHoa, int n){
	for(int i=0 ; i<n-1 ; i++ ){
		for(int j=i+1 ; j < n ; j++ ){
			if(strcmp( (HangHoa+i)->Kh->tenkh  , (HangHoa+j)->Kh->tenkh  ) < 0 ){
				struct hanghoa temp = *(HangHoa+j) ;
				*(HangHoa+j) = *(HangHoa+i);
				*(HangHoa+i) = temp;
			}
		}
	}
}

void ghiFile(struct hanghoa*HangHoa, int n){
	getchar();
	char fName[30];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	for( i = 0 ; i < n ; i++ ){
		struct hanghoa *ds = (HangHoa+i);
		fprintf(fOut,"%-20s %-10d %-20d %-7d/%-7d/%-7d %-20s %-20d\n", ds->ten, ds->soluong, ds->dongia, 
		ds->Date->ngay, ds->Date->thang, ds->Date->nam, ds->Kh->tenkh, ds->Kh->sdt);
	}
	fclose(fOut);
	
}
void xoathongtin(struct hanghoa*Hanghoa, int n){
	int ID;
	int found=0;
	printf("ID can xoa: ");
	scanf("%d", &ID);
	for(int i=0; i<n; i++){
		if(Hanghoa->id == ID){
			found = 1;
			for(int j=i; j<n; j++){
				*(Hanghoa+j) = *(Hanghoa+j+1); 
			}
		}
	}
	if(found == 0 ){
		printf("Don hang co ID %d khong ton tai.", ID);
	}
}
void docFile(struct hanghoa* HangHoa, int* n){
	FILE* fOut= fopen("hanghoa.txt" ,"r");
	int i=0;
	if(fOut) {
		for(;;) {
			struct hanghoa* ds;
			ds=(struct hanghoa*)malloc(sizeof(struct hanghoa));
			fscanf(fOut,"%20s %10d %20d %7d/%7d/%7d %20s %20d\n", ds->ten, &ds->soluong, &ds->dongia, 
			&ds->Date->ngay, &ds->Date->thang, &ds->Date->nam, ds->Kh->tenkh, &ds->Kh->sdt);
			*(HangHoa+i) = ds;
		if(feof (fOut) ){
			break;}
	
		}
	}
	fclose(fOut);
	*n=i;
}
/*void menu(){	
	struct hanghoa* HangHoa;
	int chon;
	int n;
	do{
		printf("=============== MENU ===============");
		printf("\n1.Nhap hoa don vao danh sach.");
		printf("\n2.Xuat danh sach.");
		printf("\n3.Tim kiem theo ten khach hang.");
		printf("\n4.Sap xep theo ten");
		printf("\n5.Ghi thong tin ra file.");
		printf("\n6.Xoa thong tin theo ID.");
		printf("\n0.Thoat.");
		printf("\nBan chon?");
		scanf("%d", &chon);
		
		switch(chon){
			case 0:
				break;
			case 1:
				printf("Nhap so hoa don:\n");
				scanf("%d", &n);
				HangHoa = (hanghoa*)malloc(sizeof(hanghoa) * n);
				nhapds(HangHoa,n);
				break;
			case 2:
				xuatds(HangHoa,n);
				break;
			case 3:
				fflush(stdin);
				timkiemtheoten(HangHoa,n);
				break;
			case 4:
				sapxeptheoten(HangHoa,n);
				break;
			case 5:
				ghiFile(HangHoa,n);
				break;
			case 6:
				xoathongtin(HangHoa,n);
				break;
			default:
				printf("Sai chuc nang, vui long chon lai");
				break;	
		}
	}while(chon);
}*/
int main(){
	struct hanghoa* HangHoa;
	int chon;
	int n=0;
/*	do{
		printf("=============== MENU ===============");
		printf("\n1.Nhap hoa don vao danh sach.");
		printf("\n2.Xuat danh sach.");
		printf("\n3.Tim kiem theo ten khach hang.");
		printf("\n4.Sap xep theo ten");
		printf("\n5.Ghi thong tin ra file.");
		printf("\n6.Xoa thong tin theo ID.");
		printf("\n0.Thoat.");
		printf("\nBan chon?");
		scanf("%d", &chon);
		
		switch(chon){
			case 0:
				break;
			case 1:
				printf("Nhap so hoa don:\n");
				scanf("%d", &n);
				HangHoa = (hanghoa*)malloc(sizeof(hanghoa) * n);
				nhapds(HangHoa,n);
				break;
			case 2:
				xuatds(HangHoa,n);
				break;
			case 3:
				fflush(stdin);
				timkiemtheoten(HangHoa,n);
				break;
			case 4:
				sapxeptheoten(HangHoa,n);
				break;
			case 5:
				ghiFile(HangHoa,n);
				break;
			case 6:
				xoathongtin(HangHoa,n);
				break;
			default:
				printf("Sai chuc nang, vui long chon lai");
				break;	
		}
	}while(chon);*/
	docFile(HangHoa,&n);
	xuatds(HangHoa,n);
	int i;
}



