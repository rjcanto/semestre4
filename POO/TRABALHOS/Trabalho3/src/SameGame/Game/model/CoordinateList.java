package SameGame.Game.model;

import java.util.*;

/**
 *
 * @author ncs
 */
public class CoordinateList<Coordinates> extends AbstractCollection<Coordinates>{
    private int size;
    private Node head;

    public class Node{
        private Coordinates coordinates;
        private Node link;
        public Node(Coordinates c){coordinates = c;link=null;}
        public Coordinates getCoordinates(){return coordinates;}
        public Node getNext(){return link;}
    }

    private class ListIterator<Coordinates> implements Iterator<Coordinates>{
        private Node previous;
        private Node next;
        private int idx;
        
        public ListIterator(){
            previous=head;
            next=head.link;
            idx=0;
        }

        public boolean hasNext() {
            return idx<size;
        }

        public Coordinates next() {
            if (idx<=size){
                previous=next;
                next=next.link;
                ++idx;
                return (Coordinates) previous.getCoordinates();
            }else{
                throw new NoSuchElementException();
            }
        }

        public void remove() {
            throw new UnsupportedOperationException("Not supported yet.");
        }
    }

    public CoordinateList(){
        head.link=null;
        size=0;
    }
    public Iterator<Coordinates> iterator() {
        return new ListIterator<Coordinates>();
    }
    public int size() {
        return size;
    }
    @Override
    public boolean add(Coordinates c){
        Node n = new Node(c);
        return add(n);
    }
    private boolean add(Node n){
        n.link=head.link;
        head.link=n;
        size++;
        return true;
    }


}
