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

        if (num == 1) {
            System.out.println("1/1 = 1");
            return;
        }

        // Find decimal
        int[] rems = new int[num];
        int rem = 1;
        int place = 0;

        while (rems[rem] == 0 && rem != 0) {
            rems[rem] = place;
            rem = (rem * 10) % num;
            place++;
        }

        // Print output
        System.out.println(1.0 / num);
        StringBuilder output = new StringBuilder("1/");
        output.append(args[0]);
        output.append(" = 0.");

        int cycleBegin, cycleLen;
        if (rem == 0) {
            cycleBegin = place;
            cycleLen = 0;
        } else {
            cycleBegin = rems[rem];
            cycleLen = place - cycleBegin;
        }

        System.out.println("Begin: " + cycleBegin);

        // Non-repeating part
        String dec = Integer.toString(((int) Math.pow(10, cycleBegin)) / num);
        int lenDec = dec.length();
        
        for (int i = lenDec; i < cycleBegin; i++) {
            output.append("0");
        }
        output.append(dec);

        // Repeating part
        if (cycleLen != 0) {
            output.append("(");
            // AH
            output.append("), cycle length ");
            output.append(cycleLen);
        }

        System.out.println(output.toString());
    }
}