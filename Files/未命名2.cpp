
#include <stdio.h>  
#include <string.h>  
  
typedef struct {  
    char name[50];  
    int score; // ��ʼ����  
} Player;  
  
int main() {  
    FILE *file;  
    Player players[100]; // ���������100��ѡ��  
    int playerCount = 0; // ��ǰѡ������  
    int score; // ��ί���  
    int i, j;  
    char name[50];  
    int maxScore = 0, minScore = 1000; // �����ʼ��߷ֺ���ͷֶ��ܸ�  
    int rank = 1; // ������1��ʼ  
  
    // ���ļ��ж�ȡѡ����Ϣ��������ڵĻ���  
    file = fopen("players.txt", "r");  
    if (file) {  
        fscanf(file, "%d", &playerCount); // ��ȡѡ������  
        for (i = 0; i < playerCount; i++) {  
            fscanf(file, "%s %d", players[i].name, &players[i].score); // ��ȡѡ�������ͷ���  
            maxScore = 1000;
            minScore = 20;
        }  
        fclose(file);  
    } else {  
        printf("No players found in file.\n");  
        return 1; // ���߼���ִ�У�����һ���µ��ļ������ѡ����Ϣ  
    }  
  
    // ������ί��ֵ��߼�...  
    printf("Enter the score of the judge:\n");  
    scanf("%d", &score);  
    for (i = 0; i < playerCount; i++) {  
        if (players[i].score < score) { // �����ǰѡ�ֵķ���������ί�Ĵ��...  
            players[i].score = score; // ���·���  
            if (maxScore > score) { // �����ǰ��������֮ǰ����߷�...  
                maxScore = score; // ������߷�  
                rank = 1; // ��������������ж��ѡ�ֻ����߷֣����Ƕ�����ͬ�����������  
            } else if (score == maxScore) { // �����ǰ����������߷�...  
                rank++; // ��������������ж��ѡ�ֻ����߷֣�  
            } // �����ǰ����������߷ֵ�����֮ǰ����ͷ֣�����Ҫ������������Ϊ��ǰ�����Ѿ�����͵ġ�  
        } else if (players[i].score > score) { // �����ǰѡ�ֵķ���������ί�Ĵ��...  
            // ...���������߼�...  
        } // ���������ȣ����Ը���������������ʱ�䡢������ί�Ĵ�ֵȣ������жϡ�  
    }  
    fclose(file); // �ر��ļ���������֮ǰ�򿪵Ļ���  
    file = fopen("players.txt", "w"); // ��д��ģʽ���ļ���׼��д�����ݡ�����ļ������ڣ��򴴽�����  
    if (file) { // ����ļ��Ƿ�ɹ��򿪡������ʧ�ܣ����˳�����  
        fprintf(file, "%d\n", playerCount + 1); // д���µ�ѡ���������������ѡ�ּ��룩  
        for (j = 0; j < playerCount + 1; j++) { // ������ѡ�ֵ���Ϣд���ļ���ע����������һ��Ԫ�����¼����ѡ�֡�  
            fprintf(file, "%s %d\n", players[j].name, players[j].score); // ��ѡ�ֵ������ͷ���д���ļ���ÿ��ѡ�ֵ���Ϣռһ�С�  
        } // ��������Ҫд�����Ϣд���ļ��󣬹ر��ļ���������Ǻ���Ҫ�ģ���Ϊ���ȷ���������ݶ�����ȷд���ļ���Ȼ���˳�����  
        fclose(file);  
        return 0; // ��ʾ���������˳���  
    } else {  
        printf("Failed to open file for writing.\n"); // ����޷����ļ�����д�룬�����������Ϣ���˳�����  
        return 1; // ��ʾ�����쳣�˳���  
    }  
}
