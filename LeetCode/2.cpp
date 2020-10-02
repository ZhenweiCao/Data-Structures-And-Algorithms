/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *tmp1, *tmp2;
        ListNode *node = new ListNode(0);
        result = node;
        tmp1 = l1;
        tmp2 = l2;
        int t1 = 0, t2 = 0;  //t1表示当前位的结果，t2表示进位
        while(tmp1 != nullptr && tmp2 != nullptr){         
            node->next = new ListNode(0);
            node = node->next; 
            int tmp = tmp1->val + tmp2->val + t2;
            t1 = tmp % 10;
            t2 = tmp / 10;
            node->val = t1;     
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        while(tmp1 != nullptr || t2!=0){
            if(tmp1 == nullptr){  // 如果有进位存在
                node->next = new ListNode(t2);
                break;
            }
            node->next = new ListNode(0);
            node = node->next;
            int tmp = tmp1->val + t2;
            t1 = tmp % 10;
            t2 = tmp / 10;
            node->val = t1;
            tmp1 = tmp1->next;
        }
        while(tmp2 != nullptr || t2 != 0){
            if(tmp2 == nullptr){  //  如果有进位存在
                node->next = new ListNode(t2);
                break;
            }
            node->next = new ListNode(0);
            node = node->next;
            int tmp = tmp2->val + t2;
            t1 = tmp % 10;
            t2 = tmp / 10;
            node->val = t1;        
            tmp2 = tmp2->next;
        }
        result = result->next;
        return result; 
    }
};
