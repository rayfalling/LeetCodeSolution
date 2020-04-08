#include <algorithm>
#include <vector>

class Solution {
public:
	//对不起我堕落了
	std::vector<int> sortArray(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums;
    }

    //插入
    void InsertSort(std::vector<int>& nums, int n) {
        for (auto i = 0; i < n; i++) {
	        const auto temp = nums[i];
	        auto j = i - 1;
            while (j >= 0 && nums[j] > temp) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = temp;
        }
    }
    //折半插入
    void HInsertSort(std::vector<int>& nums, int n) {
	    for (auto i = 0; i < n; i++) {
		    const auto tmp = nums[i];
	        auto low = 0;
	        auto high = i - 1;
            while (low <= high) {
	            const auto mid = low + (high - low) / 2;
                if (nums[mid] > tmp) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            for (auto j = i - 1; j >= high + 1; j--) {
                nums[j + 1] = nums[j];
            }
            nums[high + 1] = tmp;
        }
    }
    //希尔
    void ShellSort(std::vector<int>& nums, int n) {
        for (auto dk = n / 2; dk >= 1; dk = dk / 2) {
            for (auto i = dk; i < n; ++i) {
                if (nums[i] < nums[i - dk]) {
                    int tmp = nums[i], j;
                    for (j = i - dk; j >= 0 && tmp < nums[j]; j -= dk) {
                        nums[j + dk] = nums[j];
                    }
                    nums[j + dk] = tmp;
                }
            }
        }
    }
    //冒泡
    void BubbleSort(std::vector<int>& nums, int n) {
        for (auto i = 0; i < n - 1; i++) {
	        auto flag = false;
            for (auto j = n - 1; j > i; j--) {
                if (nums[j - 1] > nums[j]) {
	                std::swap(nums[j - 1], nums[j]);
                    flag = true;
                }
            }
            if (flag == false) {
                return;
            }
        }
    }
    //快排
    void QuickSort(std::vector<int>& nums, int low, int high, int n) {

        if (low < high) {
	        const auto pivotpos = partition(nums, low, high);
            QuickSort(nums, low, pivotpos - 1, n);
            QuickSort(nums, pivotpos + 1, high, n);
        }
    }
    int partition(std::vector<int>& nums, int low, int high) {
	    const auto pivot = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= pivot)--high;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;

    }
    //简单选择
    void SelectSort(std::vector<int>& nums, int n) {
        for (auto i = 0; i < n - 1; i++) {
	        auto min = i;
            for (auto j = i + 1; j < n; j++) {
                if (nums[j] < nums[min]) min = j;

            }
            if (min != i) std::swap(nums[i], nums[min]);
        }
    }
    //堆排序
    void adjust(std::vector<int>& nums, int len, int index) {
	    const auto left = 2 * index + 1; // index的左子节点
	    const auto right = 2 * index + 2;// index的右子节点

	    auto maxIdx = index;
        if (left<len && nums[left] > nums[maxIdx])     maxIdx = left;
        if (right<len && nums[right] > nums[maxIdx])     maxIdx = right;

        if (maxIdx != index)
        {
	        std::swap(nums[maxIdx], nums[index]);
            adjust(nums, len, maxIdx);
        }

    }

    // 堆排序
    void HeapSort(std::vector<int>& nums, int size) {
        for (auto i = size / 2 - 1; i >= 0; i--) {
            adjust(nums, size, i);
        }
        for (auto i = size - 1; i >= 1; i--) {
	        std::swap(nums[0], nums[i]);
            adjust(nums, i, 0);
        }
    }
};
};
