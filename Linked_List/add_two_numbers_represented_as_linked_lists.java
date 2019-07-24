package Linked_List;

public class add_two_numbers_represented_as_linked_lists {
	private class Node
	{
		int data;
		Node next;
		Node()
		{
			
		}
	}
	Node head=null;
	Node tail=null;
	int size=0;
	public void insert(int value)
	{
		Node node=new Node();
		if(head==null&&tail==null)
		{
			node.data=value;
			node.next=null;
			head=tail=node;
			this.size++;
			return;
		}
		
		node.data=value;
		node.next=head;
		head=node;
		this.size++;
		return;
		
		
	}
	public add_two_numbers_represented_as_linked_lists add(add_two_numbers_represented_as_linked_lists other)
	{
		add_two_numbers_represented_as_linked_lists list3=new add_two_numbers_represented_as_linked_lists();
		
		Node temp1=this.head;
		Node temp2=other.head;
		
		int size1=this.size;
		int  size2=other.size;
		int carry=0;
		while(temp1!=null&&temp2!=null)
		{
			int val=temp1.data+temp2.data+carry;
			 carry=(val/10);
			 val=val%10;
			 list3.insert(val);	
			 temp1=temp1.next;
			 temp2=temp2.next;
			
		}
		while(temp1!=null)
		{
			list3.insert((temp1.data+carry)%10);
			carry=temp1.data+carry/10;
			temp1=temp1.next;
		}
		while(temp2!=null)
		{
			list3.insert((temp2.data+carry)%10);
			carry=temp2.data+carry/10;
			temp2=temp2.next;
		}
		if(carry!=0)
		  list3.insert(carry);
		return list3;
	}
	public void display()
	{
		Node temp=this.head;
		while(temp!=null)
		{
			System.out.print(temp.data+"=>");
			temp=temp.next;
		}
		System.out.println("END");
	}

	public static void main(String[] args) {
		
		add_two_numbers_represented_as_linked_lists list1=new add_two_numbers_represented_as_linked_lists();
		add_two_numbers_represented_as_linked_lists list2=new add_two_numbers_represented_as_linked_lists();
		
		int arr1[]= {9,9,9};
		int arr2[]= {1,8};
		
		for(int i=arr1.length-1;i>=0;i--)
		{
			list1.insert(arr1[i]);
		}
		
		for(int i=arr2.length-1;i>=0;i--)
		{
			list2.insert(arr2[i]);
		}
		
		add_two_numbers_represented_as_linked_lists sumlist=list1.add(list2);
		sumlist.display();

	}

}
