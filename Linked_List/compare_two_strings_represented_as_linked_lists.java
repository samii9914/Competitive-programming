package Linked_List;

public class compare_two_strings_represented_as_linked_lists {
	
	private class Node
	{
		char data;
		Node next;
		Node()
		{
			
		}
	}
	Node head=null;
	Node tail=null;
	public void insert(char data)
	{
		Node node=new Node ();
		if(head==null&&tail==null)
		{
			node.data=data;
			node.next=null;
			head=tail=node;
			return;
		}
		
		node.data=data;
		node.next=null;
		tail.next=node;
		tail=node;
	}
	
	public void display()
	{
		Node temp=head;
		while(temp!=null)
		{
			System.out.println(temp.data+"=>");
			temp=temp.next;
		}
		System.out.println("END");
	}
	
	public int compare(compare_two_strings_represented_as_linked_lists other)
    {
		Node temp1=this.head;
		Node temp2=other.head;
		while(temp1!=null||temp2!=null)
		{
			if(temp1.data==temp2.data)
			{
				temp1=temp1.next;
				temp2=temp2.next;
			}
			else
			{
				if(temp1.data<temp2.data)
				{
					return -1;
				}
				else if(temp1.data>temp2.data)
				{
					return 1;
				}
			}
		}
		return 0;
	}
	public int size()
	{
		Node temp=head;
		int count=0;
		while(temp!=null)
		{
			temp=temp.next;
			count++;
		}
		return count;
	}

	public static void main(String[] args) {
		compare_two_strings_represented_as_linked_lists list1=new compare_two_strings_represented_as_linked_lists();
		compare_two_strings_represented_as_linked_lists list2=new compare_two_strings_represented_as_linked_lists();
		list1.insert('g');
		list1.insert('e');
		list1.insert('e');
		list1.insert('k');
		list1.insert('a');
		
		list2.insert('g');
		list2.insert('e');
		list2.insert('e');
		list2.insert('k');
		
		int size1=list1.size();
		int size2=list2.size();
		
		if(size1>size2)
		{
			System.out.println("1");
		}
		else if(size2>size1)
		{
			System.out.println("-1");
		}
		else
		{
			System.out.println(list1.compare(list2));
			
		}
		
		//list1.display();
		//list2.display();
		

	}

}
