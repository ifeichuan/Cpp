#include <iostream>
#include <cmath>
#include <random>
#include <vector>

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double deriv_sigmoid(double x) {
    double fx = sigmoid(x);
    return fx * (1 - fx);
}

double mes_loss(std::vector<double> y_true, std::vector<double> y_pred) {
    double sum = 0;
    for (int i = 0; i < y_true.size(); i++) {
        sum += pow(y_true[i] - y_pred[i], 2);
    }
    return sum / y_true.size();
}



class OurNeuralNetwork {
private:
    double w1, w2, w3, w4, w5, w6;
    double b1, b2, b3;

public:
    OurNeuralNetwork() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<double> dist(0.0, 1.0);

        w1 = dist(gen);
        w2 = dist(gen);
        w3 = dist(gen);
        w4 = dist(gen);
        w5 = dist(gen);
        w6 = dist(gen);

        b1 = dist(gen);
        b2 = dist(gen);
        b3 = dist(gen);
    }

    double feedforward(double x1, double x2) {
        double h1 = sigmoid(w1 * x1 + w2 * x2 + b1);
        double h2 = sigmoid(w3 * x1 + w4 * x2 + b2);
        double o1 = sigmoid(w5 * h1 + w6 * h2 + b3);
        return o1;
    }

    void train(std::vector<std::vector<double>> data, std::vector<double> all_y_trues) {
        double learn_rate = 0.1;
        int epochs = 10000;

        for (int epoch = 0; epoch < epochs; epoch++) {
            for (int i = 0; i < data.size(); i++) {
                double x1 = data[i][0];
                double x2 = data[i][1];
                double y_true = all_y_trues[i];

                double sum_h1 = w1 * x1 + w2 * x2 + b1;
                double h1 = sigmoid(sum_h1);
                double sum_h2 = w3 * x1 + w4 * x2 + b2;
                double h2 = sigmoid(sum_h2);
                double sum_o1 = w5 * h1 + w6 * h2 + b3;
                double o1 = sigmoid(sum_o1);
                double y_pred = o1;

                double d_L_d_ypred = -2 * (y_true - y_pred);
                double d_ypred_d_w5 = h1 * deriv_sigmoid(sum_o1);
                double d_ypred_d_w6 = h2 * deriv_sigmoid(sum_o1);
                double d_ypred_d_b3 = deriv_sigmoid(sum_o1);
                double d_ypred_d_h1 = w5 * deriv_sigmoid(sum_o1);
                double d_ypred_d_h2 = w6 * deriv_sigmoid(sum_o1);

                double d_h1_d_w1 = x1 * deriv_sigmoid(sum_h1);
                double d_h1_d_w2 = x2 * deriv_sigmoid(sum_h1);
                double d_h1_d_b1 = deriv_sigmoid(sum_h1);

                double d_h2_d_w3 = x1 * deriv_sigmoid(sum_h2);
                double d_h2_d_w4 = x2 * deriv_sigmoid(sum_h2);
                double d_h2_d_b2 = deriv_sigmoid(sum_h2);

                w1 -= learn_rate * d_L_d_ypred * d_ypred_d_h1 * d_h1_d_w1;
                w2 -= learn_rate * d_L_d_ypred * d_ypred_d_h1 * d_h1_d_w2;
                b1 -= learn_rate * d_L_d_ypred * d_ypred_d_h1 * d_h1_d_b1;

                w3 -= learn_rate * d_L_d_ypred * d_ypred_d_h2 * d_h2_d_w3;
                w4 -= learn_rate * d_L_d_ypred * d_ypred_d_h2 * d_h2_d_w4;
                b2 -= learn_rate * d_L_d_ypred * d_ypred_d_h2 * d_h2_d_b2;

                w5 -= learn_rate * d_L_d_ypred * d_ypred_d_w5;
                w6 -= learn_rate * d_L_d_ypred * d_ypred_d_w6;
                b3 -= learn_rate * d_L_d_ypred * d_ypred_d_b3;
            }

            if (epoch % 10 == 0) {
                std::vector<double> y_preds;
                for (int i = 0; i < data.size(); i++) {
                    double x1 = data[i][0];
                    double x2 = data[i][1];
                    double y_pred = feedforward(x1, x2);
                    y_preds.push_back(y_pred);
                }
                double loss = mes_loss(all_y_trues, y_preds);
                std::cout << "Epoch " << epoch << " loss: " << loss << std::endl;
            }
        }
    }
};

int main() {
    std::vector<std::vector<double>> data = {
        {-2, -2},
        {25, 6},
        {17, 4},
        {-15, -6}
    };

    std::vector<double> all_y_trues = {1, 0, 0, 1};

	OurNeuralNetwork network;
    network.train(data, all_y_trues);

    std::vector<double> emily = {-7, -3};
    std::vector<double> frank = {20, 2};

    std::cout << "Emily: " << network.feedforward(emily[0], emily[1]) << std::endl;
    std::cout << "Frank: " << network.feedforward(frank[0], frank[1]) << std::endl;


    return 0;
}

