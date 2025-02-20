﻿#include "quick_selection.hpp"

#include <random>
#include <utility>

namespace algorithm {
namespace sort {

// 辅助函数 - 快速选择
int
quickSelection(vector<int> &nums, int l, int r)
{
	using namespace std;
	int i = l + 1, j = r;
	while (true) {
		while (i < r && nums[i] <= nums[l]) {
			++i;
		}
		while (l < j && nums[j] >= nums[l]) {
			--j;
		}
		if (i >= j) {
			break;
		}
		swap(nums[i], nums[j]);
	}
	swap(nums[l], nums[j]);
	return j;
}

// 主函数
int
findKthLargest(vector<int> &nums, int k)
{
	int l = 0, r = nums.size() - 1, target = nums.size() - k;
	while (l < r) {
		int mid = quickSelection(nums, l, r);
		if (mid == target) {
			return nums[mid];
		}
		if (mid < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return nums[l];
}

} // namespace sort
} // namespace algorithm
