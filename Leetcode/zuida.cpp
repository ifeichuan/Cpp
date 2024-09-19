#include <iostream>
#include <vector>
#include <algorithm>

int maxScore(const std::vector<int>& a, const std::vector<int>& b) {
    int n = b.size();
    std::vector<std::pair<int, int>> contributions; // 存储 (贡献值, 原始下标)

    // 计算每个 b[i] 对应的贡献值
    for (int i = 0; i < n; ++i) {
        contributions.push_back({a[0] * b[i], i});
        contributions.push_back({a[1] * b[i], i});
        contributions.push_back({a[2] * b[i], i});
        contributions.push_back({a[3] * b[i], i});
    }

    // 按贡献值排序
    std::sort(contributions.begin(), contributions.rend());

    // 选择前四个贡献值，确保下标递增
    int maxScore = 0;
    std::vector<int> selectedIndices;
    
    for (int i = 0;i<contributions.size();i++) {
        if (selectedIndices.size() < 4) {
            selectedIndices.push_back(contributions[i].second);
            maxScore += contributions[i].first;
        }
        // 如果已经选择了四个元素，检查下标是否递增
        if (selectedIndices.size() == 4) {
            std::sort(selectedIndices.begin(), selectedIndices.end());
            if (selectedIndices[0] < selectedIndices[1] && 
                selectedIndices[1] < selectedIndices[2] && 
                selectedIndices[2] < selectedIndices[3]) {
                return maxScore; // 返回最大得分
            }
            i-=3;
            selectedIndices.clear(); // 清空选择的下标
            maxScore = 0; // 重置得分
        }
    }

    return maxScore; // 如果没有找到有效的组合，返回0
}

int main() {
    std::vector<int> a = {3,2,5,6};
    std::vector<int> b = {2,-6,4,-5,-3,2,-7};

    int result = maxScore(a, b);
    std::cout << "最大得分: " << result << std::endl;

    return 0;
}
