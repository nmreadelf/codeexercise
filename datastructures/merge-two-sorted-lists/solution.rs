// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (Some(x), None) => Some(x),
            (None, Some(y)) => Some(y),
            (Some(x), Some(y)) => {
                if x.val <= y.val {
                    Some(Box::new(ListNode {
                        val: x.val,
                        next: Solution::merge_two_lists(x.next, Some(y)),
                    }))
                } else {
                    Some(Box::new(ListNode {
                        val: y.val,
                        next: Solution::merge_two_lists(Some(x), y.next),
                    }))
                }
            }
        }
    }
}
