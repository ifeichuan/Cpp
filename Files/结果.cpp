#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include<graphics.h> //��ͼ������
#define MAX_ROWS 100 //�������
#define MAX_COLS 100 //�������
double sigmoid(double x) {	//�����

    return 1 / (1 + exp(-x));
    //���Խ�ӽ�1 ˵�����ݸ�ƫ��Ů�� ��֮ƫ������
}
double deriv_sigmoid(double x) {//������ĵ���
    double fx = sigmoid(x);
    return fx * (1 - fx);
}

double mes_loss(double* y_true, double* y_pred, int size) {//��ʧ���� 
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(y_true[i] - y_pred[i], 2);
    }
    // �����Ԫ��/�����ĺ�
    return sum / size;
}

typedef struct {	// �����綨��
	// ӵ��һ�����ز� ������Ԫ(h1,h2)
	// һ������� һ����Ԫ
    double w1, w2, w3, w4, w5, w6;
    double b1, b2, b3;
} OurNeuralNetwork;

OurNeuralNetwork* createOurNeuralNetwork() {// ����������ʵ��
    OurNeuralNetwork* network = (OurNeuralNetwork*)malloc(sizeof(OurNeuralNetwork));
    srand(time(NULL));
    network->w1 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->w2 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->w3 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->w4 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->w5 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->w6 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->b1 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->b2 = ((double)rand() / RAND_MAX) * 2 - 1;
    network->b3 = ((double)rand() / RAND_MAX) * 2 - 1;
    return network;
}

double feedforward(OurNeuralNetwork* network, double x1, double x2) {	// ǰ�� ��Ԫ��׼����
    double h1 = sigmoid(network->w1 * x1 + network->w2 * x2 + network->b1);
    double h2 = sigmoid(network->w3 * x1 + network->w4 * x2 + network->b2);
    double o1 = sigmoid(network->w5 * h1 + network->w6 * h2 + network->b3);
    return o1;
}

void train(OurNeuralNetwork* network, double data[4][2], double* all_y_trues, int data_size, int y_size) {//ѵ��������
	double learn_rate = 0.1; //ѵ���ٶ�
    int epochs = 2000;//ѵ������

    for (int epoch = 0; epoch < epochs; epoch++) {
    	//��ʼѵ��
    	//����Ŀ��:ʹlossԽ��ԽС
        for (int i = 0; i < data_size; i++) {
        	//����ƫ���� 
            double x1 = data[i][0];
            double x2 = data[i][1];
            double y_true = all_y_trues[i];
            double sum_h1 = network->w1 * x1 + network->w2 * x2 + network->b1;
            double h1 = sigmoid(sum_h1);
            double sum_h2 = network->w3 * x1 + network->w4 * x2 + network->b2;
            double h2 = sigmoid(sum_h2);
            double sum_o1 = network->w5 * h1 + network->w6 * h2 + network->b3;
            double o1 = sigmoid(sum_o1);
            double y_pred = o1;
            double d_L_d_ypred = -2 * (y_true - y_pred);
            double d_ypred_d_w5 = h1 * deriv_sigmoid(sum_o1);
            double d_ypred_d_w6 = h2 * deriv_sigmoid(sum_o1);
            double d_ypred_d_b3 = deriv_sigmoid(sum_o1);
            double d_ypred_d_h1 = network->w5 * deriv_sigmoid(sum_o1);
            double d_ypred_d_h2 = network->w6 * deriv_sigmoid(sum_o1);
            double d_h1_d_w1 = x1 * deriv_sigmoid(sum_h1);
            double d_h1_d_w2 = x2 * deriv_sigmoid(sum_h1);
            double d_h1_d_b1 = deriv_sigmoid(sum_h1);
            double d_h2_d_w3 = x1 * deriv_sigmoid(sum_h2);
            double d_h2_d_w4 = x2 * deriv_sigmoid(sum_h2);
            double d_h2_d_b2 = deriv_sigmoid(sum_h2);
            network->w1 -= learn_rate * d_L_d_ypred * d_ypred_d_h1 * d_h1_d_w1;
            network->w2 -= learn_rate * d_L_d_ypred * d_ypred_d_h1 * d_h1_d_w2;
            network->b1 -= learn_rate * d_L_d_ypred * d_ypred_d_h1 * d_h1_d_b1;
            network->w3 -= learn_rate * d_L_d_ypred * d_ypred_d_h2 * d_h2_d_w3;
            network->w4 -= learn_rate * d_L_d_ypred * d_ypred_d_h2 * d_h2_d_w4;
            network->b2 -= learn_rate * d_L_d_ypred * d_ypred_d_h2 * d_h2_d_b2;
            network->w5 -= learn_rate * d_L_d_ypred * d_ypred_d_w5;
            network->w6 -= learn_rate * d_L_d_ypred * d_ypred_d_w6;
            network->b3 -= learn_rate * d_L_d_ypred * d_ypred_d_b3;
        }
        double loss;
        if (epoch % 10 == 0) {
            double* y_preds = (double*)malloc(y_size * sizeof(double));
            for (int i = 0; i < data_size; i++) {
                double x1 = data[i][0];
                double x2 = data[i][1];
                double y_pred = feedforward(network, x1, x2);
                y_preds[i] = y_pred;
            }
            loss = mes_loss(all_y_trues, y_preds, y_size);
            circlef(epoch,600-loss*1000,1.0);
            printf("Epoch %d loss: %f\n", epoch, loss);
            free(y_preds);
        }
        
    }
}
void CreatePicture(){//��ͼ����
	       initgraph(1200,1600);
		    line(0, 700, 800, 700);
		    line(100,0,100,800);
		    outtextxy(20,100,"LOSS");
		    outtextxy(580,800,"Epochs");
}

int importdata(double testdata[MAX_ROWS][3]){//��������
        	    FILE *file = fopen("./data.txt","rb+");
	    if(file==NULL){
			printf("�ļ�������\n");
		}
		int row = 0,col = 0,secondvalue,sum=0,l=0;
		while(!feof(file)){
			int value = fgetc(file);
			if(value=='\n'){
				row++;
				col = 0;
			}
			else if(value >='0' && value <= '9'){
				sum = sum*10 + value-'0';
				col++;
			}
			else if(secondvalue>='0'&&secondvalue<='9'&&value==39){
//				printf("%c",secondvalue);
				if(l==0){
					sum -=66;//�й���Ů���ƽ��ֵ
				}
				if(l==1) sum-=147.7097;//�й���Ů����ƽ��ֵ
				//���ݱ�׼��
				testdata[row][l++] = sum;
				l = l==3?0:l;
				sum = 0;
			}
			
			secondvalue = value;
		}
		return row;
//		for(int i=0;i<=MAX_ROWS&&testdata[i][0];i++){
//			for(int j=0;j<=MAX_COLS&&testdata[i][j];j++){
//				printf("%lf ",testdata[i][j]);
//			}
//		}
//	}
}
int main() {//������
    double testdata[MAX_ROWS][3] = {0.0};
    int lines = importdata(testdata);
    double traindata[10][2];
    double all_y_trues[10];
    for(int i=0;i<10;i++){
    	traindata[i][0] =testdata[i][0];
    	traindata[i][1] = testdata[i][1];
    	all_y_trues[i] = testdata[i][2];
    	
	}
    OurNeuralNetwork* network = createOurNeuralNetwork();
	CreatePicture();
    train(network, traindata, all_y_trues, 10, 10);
    for(int i=0;i<lines;i++){
		printf("%.1lf\t%.1lf\t:%.5lf\t��ʵ���:%.0lf\n",testdata[i][0],testdata[i][1],feedforward(network,testdata[i][0],testdata[i][1]),testdata[i][2]);
	}
	printf("��λ: ���-66(Ӣ��),����-147(��)\n");
    printf("��������˳�:");
    getchar();
    closegraph();
    free(network);
    return 0;
}
