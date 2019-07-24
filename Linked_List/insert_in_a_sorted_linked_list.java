package Linked_List;

public class insert_in_a_sorted_linked_list {
	private class Node
	{
		int data;
		Node next;
	}
	Node head=null;
	Node tail=null;
	public void insertsorted(int value)
	{
		Node node=new Node();
		if(head==null&&tail==null)
		{
			node.data=value;
			node.next=null;
			head=node;
			tail=node;
			return;
		}
		
		Node temp=head;
		if(temp.data>value)
		{
			node.data=value;
			node.next=head;
			head=node;
			return;
		}
		while(temp.next!=null&&temp.next.data<value)
		{
			temp=temp.next;
		}
		if(temp==tail)
		{
			node.data=value;
			node.next=null;
			temp.next=node;
			tail=node;
		}
		else
		{
		node.data=value;
		node.next=temp.next;
		temp.next=node;
		}
		
		
	}
	
	public void display()
	{
		Node temp=head;
		while(temp!=null)
		{
			System.out.print(temp.data+"=>");
			temp=temp.next;
		}
		System.out.println("END");
	}

	public static void main(String[] args) {
	    insert_in_a_sorted_linked_list list=new insert_in_a_sorted_linked_list();
	    list.insertsorted(5);
	    list.insertsorted(9);
	    list.insertsorted(1);
	    list.insertsorted(3);
	    list.insertsorted(2);
	    list.display();

	}
}


