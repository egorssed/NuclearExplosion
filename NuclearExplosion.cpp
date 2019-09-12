#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <stdbool.h> 
#include <time.h> 
#include <conio.h> 
#include <process.h> 
const float RAND_MAX_F = RAND_MAX;
const double PI = 3.1415926535897932384626433832795;
const int N0 = 1;
const float R = 5;
double get_rand() {
	return rand() / RAND_MAX_F;
}
double get_rand_range(const double& min,const double& max) {
	return get_rand() * (max - min) + min;
}
void getLambda( const int& N, double *L) { // длина свободного пробега нейтрона
	for (int i = 0; i < N; i++) {
		double r = get_rand();
		L[i] = -log(r);
	}
}
int collisionProbability() { //Вероятность рождения N вторичных нейтронов после столкновения
	double p = get_rand_range(0, 1);
	if (p < 0.83) return 1;
	if ((p >= 0.83) && (p < 0.9)) return 2;
	if ((p >= 0.9) && (p < 0.95)) return 3;
	if ((p >= 0.95) && (p < 0.975)) return 4;
	return 0;
}
struct Neutron {
	double r;
	double t;
	double f;
	double vt;
	double vf; //представление координат-импульсов в сферических координатах
};
struct NeutronDec { //представление в декартовых координатах
	double x, y, z;
	double vx, vy, vz;
};
void getVdirection(double *vt, double *vf) { //определение направления и скорости движения вторичного нейтрона
	*vf = get_rand_range(0, 2 * PI);
	double b = get_rand_range(-1, 1);
	*vt = acos(b);
}
void getb(int *b, int *N) {
	int SecNtotal = 0;
	for (int i = 0; i < *N; i++) {
		b[i] = collisionProbability();
		//printf("b[%d] - %d\n", i, b[i]);
		SecNtotal += b[i];
	}
	*N = SecNtotal;
}
void collision(struct Neutron *P, struct Neutron *P2, int *N, int *b) { //обработка столкновения нейтрона с ядром
	int curN = 0;
	for (int i = 0; i < *N; i++) {
		for (int j = curN; j < curN + b[i]; j++) {
			P2[j].r = P[i].r;
			P2[j].f = P[i].f;
			P2[j].t = P[i].t;
			getVdirection(&P2[j].vt, &P2[j].vf);
		}
		curN += b[i];
	}
	*N = curN;
}
void shift(struct Neutron *P, int N, double *L) { //движение нейтронов
	struct NeutronDec *P1 = (struct NeutronDec *)malloc(N * sizeof(struct NeutronDec));
	for (int i = 0; i < N; i++) {
		P1[i].x = P[i].r*sin(P[i].t)*cos(P[i].f);
		P1[i].y = P[i].r*sin(P[i].t)*sin(P[i].f);
		P1[i].z = P[i].r*cos(P[i].t);
		P1[i].vx = sin(P[i].vt)*cos(P[i].vf);
		P1[i].vy = sin(P[i].vt)*sin(P[i].vf);
		P1[i].vz = cos(P[i].vt);
		P1[i].x += L[i] * P1[i].vx;
		P1[i].y += L[i] * P1[i].vy;
		P1[i].z += L[i] * P1[i].vz;
		P[i].r = sqrt(P1[i].x*P1[i].x + P1[i].y*P1[i].y + P1[i].z*P1[i].z);
		if (P[i].r == 0) {
			P[i].t = 0;
		}
		else {
			P[i].t = acos(P1[i].z / P[i].r);
		}
		if (sin(P[i].t) == 0) {
			P[i].f = 0;
		}
		else {
			P[i].f = acos(P1[i].x / (P[i].r*sin(P[i].t)));
		}
	}
}
int * cleanCount(struct Neutron *P, int *N, int *count) {
	int *NewN = (int *)calloc(*N, sizeof(int));
	int c_count = 0;
	*count = 0;
	for (int i = 0; i < *N; i++) {
		if (P[i].r > R) {
			NewN[i] = 1;
			c_count++;
		}
	}

	for (int i = 0; i < *N; i++) {
		if (P[i].r > R) {
		}
	}
	for (int i = 0; i < *N; i++) {
		if (P[i].r > R) {
		}
	}
	*count = c_count;
	return NewN;
}
struct Neutron * clean(struct Neutron *P, int *N, const int count, int * NewN) {
	struct Neutron *P1 = (struct Neutron *)malloc((*N - count) * sizeof(struct Neutron));
	int countj = 0;
	int i = 0;
	for (int j = 0; j < *N; j++) {
		if (NewN[j] == 0) {
			P1[i] = P[j];
			i++;
		}
	}
	for (int i = 0; i < *N; i++) {
		if (P[i].r > R) {
		}
	}
	for (int i = 0; i < *N - count; i++) {
		if (P1[i].r > R) {
			printf("P1[%d].r - %f \n", i, P1[i].r);
		}
	}
	*N = *N - count;
	return P1;
}


int main(int argc, char** argv) {
	srand((unsigned int)time(NULL));
	int Nfin = 0;
	int Ninf = 0;
	for (int j = 0; j < 10000; j++) {
		struct Neutron *P = (struct Neutron *)malloc(N0 * sizeof(struct Neutron));
		P[0].r = 0;
		P[0].f = 0;
		P[0].t = 0;
		getVdirection(&P[0].vt, &P[0].vf);
		int N = N0;
		int count = 0;
		printf("\n");
		for (int i = 0; i < 20; i++) {
			double *L = (double *)calloc(N, sizeof(double));
			getLambda(N, L); //получение длины свободного пробега
			shift(P, N, L); //смещение нейтронов
			int * NewN = cleanCount(P, &N, &count); //исключение нейтронов , улетевших из области ядерной реакции
			P = clean(P, &N, count, NewN);
			int *b = (int *)malloc(N * sizeof(int));
			int N1 = N;
			getb(b, &N1);
			struct Neutron *P2 = (struct Neutron *)malloc(N1 * sizeof(struct Neutron));
			collision(P, P2, &N, b); //обработка столкновений нейтронов в области ядерной реакции с ядрами
			P = (struct Neutron *)realloc(P, N1 * sizeof(struct Neutron));
			for (int j = 0; j < N1; j++) {
				P[j] = P2[j];
			}
			printf("generation - %d Number of neutrons  - %d\n", i, N);
			if (N == 0) {
				printf("\n");
				Nfin++;
				break;
			}
			if (i == 19) Ninf++;
			free(L);
			free(NewN);
			free(b);
			free(P2);
		}
		printf("amount of finite processes - %d amount of infinite processes - %d\n\n", Nfin, Ninf);
	}
	getchar();
	return 0;



}