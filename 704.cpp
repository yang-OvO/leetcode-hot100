
template <typename ForwardIt, typename ValueT>
ForwardIt BinraySearch(ForwardIt begin, ForwardIt end, ValueT value)
{
    ForwardIt left = begin;
    ForwardIt right = std::next(begin, std::distance(begin, end)-1);
    while (std::distance(left, right) >= 0) {
        ForwardIt mid = std::next(left, std::distance(left, right) / 2);
        typename std::iterator_traits<ForwardIt>::value_type mid_value = *mid;
        if (mid_value == value) {
            return mid;
        } else if (mid_value < value) {
            std::advance(left, std::distance(left, mid) + 1);
        } else {
            // If right move to the left of left itertaor
            if (std::distance(left, mid) == 0) {
                break;
            } else {
                right = std::next(left, std::distance(left, mid) - 1);
            }
        }
    }
    return end;
}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = BinraySearch(nums.begin(), nums.end(), target);
        if (it == nums.end()) {
            return -1;
        } else {
            return std::distance(nums.begin(), it);
        }
    }
};