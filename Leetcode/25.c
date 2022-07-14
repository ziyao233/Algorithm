struct ListNode {
	int val;
	struct ListNode *next;
};

#include<stdio.h>
#include<stdbool.h>

#define reverseKGroup reverse_k_group

struct ListNode* reverse_k_group(struct ListNode* head, int k){
	struct ListNode **lastPointer = &head;
	struct ListNode *p = head;
	while (true) {
		int count = 0;
		struct ListNode *groupEnd = p;
		while (groupEnd && count < k - 1) { 
			groupEnd = groupEnd->next;
			count++;
		}
		if (count != k - 1 || !groupEnd)
			break;

		*lastPointer = groupEnd;
		lastPointer = &p->next;
		struct ListNode *tmp = p,*next;
		struct ListNode *nextGroupStart = groupEnd->next;
		p = p->next;
		while (p != nextGroupStart) {
			next = p->next;
			p->next = tmp;
			tmp = p;
			p = next;
		}
	}
	*lastPointer = p;
        
        return head;
}

int main()
{
	struct ListNode array[5] = {
					{
						.val = 1,
						.next = array + 1,
					},
					{
						.val = 2,
						.next= array + 2,
					},
					{
						.val = 3,
						.next = array + 3,
					},
					{
						.val = 4,
						.next = array + 4,
					},
					{
						.val = 5,
						.next = NULL,
					}
				   };

	struct ListNode *head = reverse_k_group(array,3);

	while (head) {
		printf("%d\n",head->val);
		head = head->next;
	}

	return 0;
}
