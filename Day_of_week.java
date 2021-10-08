class Day_of_week {
    public static void main(String[] args) {
        printDayofTheWeek(0);
    }
    public static void printDayofTheWeek(int day){

        switch(day){
            case 0:
                System.out.println("Monday");
                break;
            case 1:
                System.out.println("Tuesday");
                break;
            case 2:
                System.out.println("wednesday");
                break;
            case 3:
                System.out.println("thursday");
                break;
            case 4:
                System.out.println("Friday");
                break;
            case 5:
                System.out.println("saturday");
                break;
            case 6:
                System.out.println("sunday");
                break;
            default:
                System.out.println("Invalid Day");
                break;

        }

    }
}
