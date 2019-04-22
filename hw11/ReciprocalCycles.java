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
        int arg;
        try {
            arg = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            arg = -1;
        }

        if (arg < 1 || arg > 2000) {
            System.out.println("Error: Denominator must be an integer in " 
                + "[1, 2000]. Received '" + args[0] + "'.");
        }
    }
}