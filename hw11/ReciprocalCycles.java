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

        // Hardcode 1 case
        if (num == 1) {
            System.out.println("1/1 = 1");
            return;
        }

        // Find position/length of loop
        int[] remPlaces = new int[num];
        int rem = 1;
        int place = 1;

        while (remPlaces[rem] == 0 && rem != 0) {
            remPlaces[rem] = place;
            rem = (rem * 10) % num;
            place++;
        }

        // Find digits
        int n = 1;
        int[] digits = new int[place];
        for (int i = 0; i < place; i++) {
            digits[i] = n / num;
            n = n % num * 10;
        }

        // Print output
        StringBuilder output = new StringBuilder("1/");
        output.append(args[0]);
        output.append(" = 0.");

        int cycleBegin, cycleLen;
        if (rem == 0) {
            cycleBegin = place;
            cycleLen = 0;
        } else {
            cycleBegin = remPlaces[rem];
            cycleLen = place - cycleBegin;
        }

        // Non-repeating part
        for (int i = 1; i < cycleBegin; i++) {
            output.append(digits[i]);
        }

        // Repeating part
        if (cycleLen != 0) {
            output.append("(");
            
            for (int i = 0; i < cycleLen; i++) {
                output.append(digits[cycleBegin + i]);
            }

            output.append("), cycle length ");
            output.append(cycleLen);
        }

        System.out.println(output.toString());
    }
}
