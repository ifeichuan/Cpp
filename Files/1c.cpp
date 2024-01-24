#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include<graphics.h>

double sigmoid(double x) {
	//激活函数
    return 1 / (1 + exp(-x));
}

double deriv_sigmoid(double x) {
	//激活函数的导数
    double fx = sigmoid(x);
    return fx * (1 - fx);
}

double mes_loss(double* y_true, double* y_pred, int size) {
	//损失函数 
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(y_true[i] - y_pred[i], 2);
    }
    // 求各个元素/个数的和
    return sum / size;
}

typedef struct {
	// 神经网络定义
	// 拥有一个隐藏层 两个神经元(h1,h2)
	// 一个输出层 一个神经元
    double w1, w2, w3, w4, w5, w6;
    double b1, b2, b3;
} OurNeuralNetwork;

OurNeuralNetwork* createOurNeuralNetwork() {
	// 创建神经网络实例
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

double feedforward(OurNeuralNetwork* network, double x1, double x2) {
	// 前馈 神经元标准操作
    double h1 = sigmoid(network->w1 * x1 + network->w2 * x2 + network->b1);
    double h2 = sigmoid(network->w3 * x1 + network->w4 * x2 + network->b2);
    double o1 = sigmoid(network->w5 * h1 + network->w6 * h2 + network->b3);
    return o1;
}

void train(OurNeuralNetwork* network, double data[4][2], double* all_y_trues, int data_size, int y_size) {
    double learn_rate = 0.1; //训练速度
    int epochs = 10000;//训练次数

    for (int epoch = 0; epoch < epochs; epoch++) {
    	//开始训练
        for (int i = 0; i < data_size; i++) {
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

int main() {
    double data[4][2] = {
        {-2, -2},
        {25, 6},
        {17, 4},
        {-15, -6}
    };
    double all_y_trues[4] = {1, 0, 0, 1};
    OurNeuralNetwork* network = createOurNeuralNetwork();
        initgraph(1200,1600);
	    line(0, 700, 800, 700);
	    line(100,0,100,800);
	    outtextxy(80,100,"LOSS");
	    outtextxy(580,700,"Epochs");
    train(network, data, all_y_trues, 4, 4);
    double emily[2] = {-7, -3};
    double frank[2] = {20, 2};
    printf("Emily: %f\n", feedforward(network, emily[0], emily[1]));
    printf("Frank: %f\n", feedforward(network, frank[0], frank[1]));
    printf("按任意键退出:");
    getchar();
    closegraph();
    free(network);
    return 0;
}
