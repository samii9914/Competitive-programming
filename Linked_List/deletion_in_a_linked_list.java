package Linked_List;


public class deletion_in_a_linked_list {
	private class Node
	{
		int data;
		Node next;
		Node()
		{
			
		}
	}
	Node head;
	Node tail;
	
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
	
	public void delete(int index)throws Exception
	{
		if(head==null&&tail==null)
		{
			throw new Exception("list is empty");
		}
		
		if(head==tail)
		{
			head=tail=null;
			return;
		}
		
		int count=0;
		Node temp=head;
		if(index==1)
		{
			head=head.next;
			return;
		}
		while(count<index-2&&temp!=null)
		{
			temp=temp.next;
			count++;
		}
		if(temp.next.next==null)
		{
			temp.next=null;
		}
		else
		{
		temp.next=temp.next.next;
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


	public static void main(String[] args)throws Exception {
		deletion_in_a_linked_list list=new deletion_in_a_linked_list();
		list.insertsorted(5);
		list.insertsorted(1);
		list.insertsorted(2);
		list.insertsorted(9);
		list.insertsorted(3);
		list.display();
		list.delete(3);
		list.display();
		list.delete(4);
		list.display();
		list.delete(1);
		list.display();
		
		

	}

}
