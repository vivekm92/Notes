class Solution {
public:

    // T(n) : O(logn), S(n) : O(1)
    int findPeakElement1(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) { return 0; }

        int l = 0, r = n - 1;
        while (l <= r) {

            int mid = l + (r - l) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            else if (mid == 0 || nums[mid] > nums[mid  - 1]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return -1;
    }

    // helper method
    int find_peak(vector<int>& nums, int l, int r) {
        if (l <= r) {
            int mid = l + (r - l) / 2;
            if ((mid == 0 || nums[mid] >= nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] >= nums[mid + 1])) {
                return mid;
            }
            else if (mid == 0 || nums[mid] >= nums[mid - 1]) {
                return find_peak(nums, mid + 1, r);
            }
            return find_peak(nums, l, mid - 1);
        }
        return -1;
    }

    // T(n) : O(logn), S(n) : O(1)
    int findPeakElement2(vector<int>& nums) {
        return find_peak(nums, 0, nums.size() - 1);
    }


    // T(n) : O(logn), S(n) : O(1)
    int findPeakElement3(vector<int>& nums) {

        int l = 0, r = nums.size() - 1;
        while (l < r) {

            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

    // helper method
    int find_peak1(vector<int>& nums, int l, int r) {

      if (l >= r) return l;

      int mid = l + (r - l) / 2;
      if (nums[mid] > nums[mid + 1]) {
          return find_peak1(nums, l, mid);
      }

      return find_peak1(nums, mid + 1, r);
    }

    // T(n) : O(logn), S(n) : O(1)
    int findPeakElement4(vector<int>& nums) {
      return find_peak1(nums, 0, nums.size() - 1);
    }

};
