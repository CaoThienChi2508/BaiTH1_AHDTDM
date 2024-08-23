#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "stdlib.h"

// NHAP MANG
int Nhap(int a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
		{
			a[i][j] = rand() % 51;
		}
	return 0;
}

// XUAT MANG
int Xuat(int a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	return 0;
}

// TONG GIA TRI TUNG DONG
int Sum_Dong(int a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		int tong = 0;
		for (int j = 0; j < cot; j++)
			tong+=a[i][j];
		printf("\nTong dong %d: %d", i, tong);
	}
	return 0;
}

// PHAN TU LON NHAT TUNG COT
int Max_Cot(int a[][100], int dong, int cot)
{
	for (int i = 0; i < cot; i++)
	{
		int  max = a[i][0];
		for (int j = 0; j < dong; j++)
			if (a[i][j]>max)
				max=a[i][j];
		printf("\nPhan tu lon nhat cot %d: %d", i, max);
	}
	return 0;
}

// CAC PHAN TU THUOC DUONG BIEN: TREN - DUOI - TRAI - PHAI
int DuongBien(int a[][100], int dong, int cot)
{
	// Bien Tren
	printf("\nBien Tren: ");
	for (int j = 0; j < cot; j++)
		printf("%5d", a[0][j]);

	// Bien Duoi
	printf("\nBien Duoi: ");
	for (int j = 0; j < cot; j++)
		printf("%5d", a[dong-1][j]);
	
	// Bien Trai
	printf("\nBien Trai: ");
	for (int i = 0; i < dong; i++)
		printf("%5d", a[i][0]);

	// Bien Phai
	printf("\nBien Phai: ");
	for (int i = 0; i < dong; i++)
		printf("%5d", a[i][cot-1]);

	return 0;
}

//// CAC PHAN TU CUC DAI
//int Max(int a[][100], int dong, int cot)
//{
//	for (int i = 0; i < dong; i++)
//	{
//		for (int j = 0; j < cot; j++)
//			// TH Bien Tren
//
//	}
//	return max;
//}

// XUAT DONG CHI CHUA SO CHAN
int Dong_So_Chan(int a[][100], int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			if ((a[i][j] % 2)==0)
				dem++;
		if (dem==(cot-1))
			for (int j = 0; j < cot; j++)
				printf("%5d", a[i][j]);
	}
	return 0;
}
int KTPhanTu(int a[][100], int f, int cotkt, int x)
{
	for (int k = 0; k < f; k++) // Duyet theo cot
	{
		if (a[k][cotkt] == x)
			return 1; // Da co tham so trong khung
	}
	return 0; // Khong co tham so trong khung
}

// CHUONG TRINH CHINH
int main()
{
	printf("\tMANG 2 CHIEU\n\n");
	int a[100][100];
	int dong, cot;

	printf("Nhap so dong: ");
	scanf("%d", &dong);
	printf("Nhap so cot: ");
	scanf("%d", &cot);
	// CAU 1
	printf("\nCAU 1: \n");
	Nhap(a, dong, cot);
	Xuat(a, dong, cot);
	// CAU 2
	printf("\nCAU 2: ");
	Sum_Dong(a, dong, cot);
	// CAU 3
	printf("\n\n\tCAU 3: ");
	Max_Cot(a, dong, cot);
	// CAU 4
	printf("\n\nCAU 4: ");
	DuongBien(a, dong, cot);
	//// CAU 5
	//printf("\n\nCAU 5: ");
	//printf("Phan tu cuc dai: %d ",Max(a, dong, cot));
	// CAU 8
	printf("\n\nCAU 8: ");
	Dong_So_Chan(a, dong, cot);
	_getch();
	return 0;
}