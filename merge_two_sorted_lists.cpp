//! template version 1.1
//https://leetcode.com/problems/merge-two-sorted-lists/submissions/
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

// level:easy

// Definition for singly-linked list.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct LinkedList
{
  ListNode *head = NULL;
  void add(int x)
  {
    ListNode *pNewNode = new ListNode;
    pNewNode->val = x;
    pNewNode->next = NULL;

    if (head == NULL)
    {
      head = pNewNode;
    }
    else
    {
      ListNode *pCurrentNode = head;
      // talep edilen değere kadar gidilecek,
      // edge case listeden büyük değerler için if exception yapılacak
      while (pCurrentNode->next != NULL)
      {
        // cout << pCurrentNode->val << endl;
        pCurrentNode = pCurrentNode->next;
      }
      pCurrentNode->next = pNewNode;
    }
  };

  void get(int x)
  {
    ListNode *pCurrentNode = head;
    // talep edilen değere kadar gidilecek,
    // edge case listeden büyük değerler için if exception yapılacak
    for (int i = 0; i < x; i++)
    {
      pCurrentNode = pCurrentNode->next;
    }
    cout << pCurrentNode->val;
    cout << endl;
  };

  void del(int x)
  {

    ListNode *pCurrentNode = head;
    // x-1 değerine git
    for (int i = 0; i < x - 1; i++)
    {
      pCurrentNode = pCurrentNode->next;
    }
    // ondan önceki değerin nextini x değerinden sonraki değeri göster
    ListNode *pPreTempNode = pCurrentNode;
    for (int i = x - 1; i < x + 1; i++)
    {
      pCurrentNode = pCurrentNode->next;
    }
    pPreTempNode->next = pCurrentNode;
  }

  void printList()
  {
    ListNode *pCurrentNode = head;
    // talep edilen değere kadar gidilecek,
    // edge case listeden büyük değerler için if exception yapılacak
    while (pCurrentNode != NULL)
    {
      cout << pCurrentNode->val << " ";
      pCurrentNode = pCurrentNode->next;
    }
    cout << endl;
  }
  void insert(int node, const int &value)
  {

  }
  void updateValue(int node, const int &value)
  {
    // hangi node için node değeri update olacak
    ListNode *pCurrentNode = head;
    // talep edilen değere kadar gidilecek,
    // edge case listeden büyük değerler için if exception yapılacak
    for (int i = 0; i < node; i++)
    {
      pCurrentNode = pCurrentNode->next;
    }
    pCurrentNode->val = value;
  }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  // listlerin boş olma durumları için edge caseler
  if (list1 == NULL)
    return list2;
  if (list2 == NULL)
    return list1;
  ListNode *head;
  ListNode *temp;
  // hangi list nodedun ilk elemani daha kücükse head o node ile başlayacak
  if (list1->val < list2->val)
  {
    temp = list1;
    head = list1;
    list1 = list1->next;
  }
  else
  {
    temp = list2;
    head = list2;
    list2 = list2->next;
  }
  // eğer iki listte boş değilse
  while (list1 != NULL && list2 != NULL)
  {
    // list1 değerinin list2 den küçük olması durumu için
    if (list1->val < list2->val)
    {
      temp->next = list1;
      list1 = list1->next;
    }
    // list1 değerinin list2 den büyük olması durumu için
    else
    {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }
  // listede kalan diğer elemanlar için
  while (list1 != NULL)
  {
    temp->next = list1;
    list1 = list1->next;
    temp = temp->next;
  }
  while (list2 != NULL)
  {
    temp->next = list2;
    list2 = list2->next;
    temp = temp->next;
  }
  return head;
}

int main()
{
  bool output;
  vector<string> beklenen{};
  vector<string> test{};
  vector<string> test2{};

  LinkedList a;

  // a.printList();
  // a.add(5); //
  // // a.printList();
  // a.add(4);
  // // a.printList();
  // a.add(2);
  // a.printList();
  // // a.printList();
  // // a.get(0); // 4 print out yapacak
  // // a.get(1);
  // // a.get(2);
  // // a.get(3);
  // a.del(1);
  // a.printList();

  // a.updateValue(1, 500);
  // a.printList();
  // for (int i = 0; i < test.size(); i++)
  // {
  // mergeTwoLists();
  //   cout << "sonuc= " << output << " ------- "
  //        << "beklenen= " << beklenen[i] << endl;
  // }
  return 0;
}