
#include <stdio.h>  
#include <string.h>  
  
typedef struct {  
    char name[50];  
    int score; // 初始分数  
} Player;  
  
int main() {  
    FILE *file;  
    Player players[100]; // 假设最多有100名选手  
    int playerCount = 0; // 当前选手数量  
    int score; // 评委打分  
    int i, j;  
    char name[50];  
    int maxScore = 0, minScore = 1000; // 假设初始最高分和最低分都很高  
    int rank = 1; // 排名从1开始  
  
    // 从文件中读取选手信息（如果存在的话）  
    file = fopen("players.txt", "r");  
    if (file) {  
        fscanf(file, "%d", &playerCount); // 读取选手数量  
        for (i = 0; i < playerCount; i++) {  
            fscanf(file, "%s %d", players[i].name, &players[i].score); // 读取选手姓名和分数  
            maxScore = 1000;
            minScore = 20;
        }  
        fclose(file);  
    } else {  
        printf("No players found in file.\n");  
        return 1; // 或者继续执行，创建一个新的文件并添加选手信息  
    }  
  
    // 处理评委打分等逻辑...  
    printf("Enter the score of the judge:\n");  
    scanf("%d", &score);  
    for (i = 0; i < playerCount; i++) {  
        if (players[i].score < score) { // 如果当前选手的分数低于评委的打分...  
            players[i].score = score; // 更新分数  
            if (maxScore > score) { // 如果当前分数高于之前的最高分...  
                maxScore = score; // 更新最高分  
                rank = 1; // 重置排名（如果有多个选手获得最高分，他们都有相同的最高排名）  
            } else if (score == maxScore) { // 如果当前分数等于最高分...  
                rank++; // 增加排名（如果有多个选手获得最高分）  
            } // 如果当前分数低于最高分但高于之前的最低分，则不需要更新排名，因为当前排名已经是最低的。  
        } else if (players[i].score > score) { // 如果当前选手的分数高于评委的打分...  
            // ...处理降级等逻辑...  
        } // 如果分数相等，可以根据其他条件（如时间、其他评委的打分等）进行判断。  
    }  
    fclose(file); // 关闭文件句柄（如果之前打开的话）  
    file = fopen("players.txt", "w"); // 以写入模式打开文件，准备写入数据。如果文件不存在，则创建它。  
    if (file) { // 检查文件是否成功打开。如果打开失败，则退出程序。  
        fprintf(file, "%d\n", playerCount + 1); // 写入新的选手数量（如果有新选手加入）  
        for (j = 0; j < playerCount + 1; j++) { // 将所有选手的信息写入文件。注意数组的最后一个元素是新加入的选手。  
            fprintf(file, "%s %d\n", players[j].name, players[j].score); // 将选手的姓名和分数写入文件。每个选手的信息占一行。  
        } // 将所有需要写入的信息写入文件后，关闭文件句柄。这是很重要的，因为这会确保所有数据都被正确写入文件。然后退出程序。  
        fclose(file);  
        return 0; // 表示程序正常退出。  
    } else {  
        printf("Failed to open file for writing.\n"); // 如果无法打开文件进行写入，则输出错误信息并退出程序。  
        return 1; // 表示程序异常退出。  
    }  
}
