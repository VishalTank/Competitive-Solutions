package Advanced;

public class FactoryPattern {
    //copy from here
    switch (order){
        case "pizza": return new Pizza();
        case "cake" : return new Cake();
        default : return null;
    }
    //to here
}
