package Memento_Command;

import java.util.ArrayList;

public class caretaker {
	//�ä��|�����s��memento �O�z�Lorigenator�����ʪ��h�s����
	//�u�smemento
	//�ǻ�memento ����L����
	
	ArrayList<memento> array = new ArrayList<memento>();
	
	public void addMemento(memento m) {
		array.add(m);
	}
	
	public memento getMemento(int index) {
		return array.get(index);
	}
}
