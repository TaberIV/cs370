/**********************************************************************
 * Authors: Taber McFarlin, Chris Byrne, and Luke L
 * We pledge our honor that we have abided by the Stevens Honor System
 *********************************************************************/


class ReciprocalCycles {
    public static void main(String[] args) {
        // Check arguments
        // Number of arguments 
        int argc = args.length;
        if (argc != 1) {
            System.out.println("Usage: java ReciprocalCycles <denominator>");
            return;
        }

        // Verify argument
        int num;
        try {
            num = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            num = -1;
        }

        if (num < 1 || num > 2000) {
            System.out.println("Error: Denominator must be an integer in " 
                + "[1, 2000]. Received '" + args[0] + "'.");
            return;
        }

        // Find decimal
        int[] rems = new int[num];
        int rem = 1;
        int place = 0;

        while (rems[rem] == 0 && rem != 0) {
            System.out.println(rems[rem]);
            rems[rem] = place;
            rem = (rem * 10) % num;
            place++;
        }


        int begin, end;
        if (rem == 0) {
            begin = 0;
            end = 0;
        } else {
            begin = rems[rem];
            end = place;
        }

        // Print output
        StringBuilder output = new StringBuilder("1/");
        output.append(args[0]);
        output.append(" = 0.");

        // Before repeating part
        for (int p = 1; p < begin; p++) {
            output.append(((int) Math.pow(10, p)) / num);
        }

        // Repeating part
        if (end != 0) {
            output.append("(");
            for (int p = begin; p < end; p++) {
                output.append(((int) Math.pow(10, p)) / num);
            }
            output.append("), cycle length ");
            output.append(end - begin);
        }

        System.out.println(output.toString());
        System.out.println("Begin: " + begin + "\nEnd: " + end);
    }
}