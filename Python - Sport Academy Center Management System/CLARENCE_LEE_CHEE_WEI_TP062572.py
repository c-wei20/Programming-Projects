#CLARENCE LEE CHEE WEI
#TP062572


def main_menu_function():
    continue_opt = 1
    check = 0
    while continue_opt == 1:
        opt = input("\t ================================================\n"
                    "\t *** Welcome to REAL CHAMPIONS SPORT ACADEMY ***\n"
                    "\t ================================================"
                    "\nAccess as: \n\t[1] Admin\n\t[2] Student\n\t[3] Registered Student\n\t[4] Exit \n"
                    "\nSelect Your Access Identity (Enter Number): ")
        while opt not in ('1','2','3','4'):
            print("Invalid Input!")
            opt = input("Enter the number again: ")
        if opt == '1':
            continue_opt = admin_login_function()
        elif opt == '2':
            continue_opt = student_function()
        elif opt == '3':
            continue_opt = student_login_function()
        else:
            check = 1
        if check == 1:
            opt = input("Do you want to exit? 'Y' for YES, 'N' for NO: ")
            while opt not in ('Y','y','N','n'):
                print("Invalid Input!")
                opt = input("Do you want to exit? ( Y / N ): ")
            if opt == 'Y' or opt == 'y':
                continue_opt = 0
    print("Good Bye!!!")


#Admin Info: RA001, Admin, RCSA5970
def admin_login_function():
    print("\n\t*** Welcome Admin, please login to access functionalities ***\n")
    flag = 1
    while flag == 1:
        myfile = open("data_file/admin_file.txt", "r")
        admin_id = input("Admin Name/ID: ")
        admin_pass = input("Password: ")
        x = 0
        for lines in myfile:
            line = lines.rstrip()
            if admin_id == line.split('\t')[0] or admin_id == line.split('\t')[1] and admin_pass == line.split('\t')[2]:
                x = 1
        if x == 1:
            print("\n*** Login Successful! ***")
            continue_opt = admin_function()
            flag = 0
        elif x == 0:
            print("User not found! Your Admin ID or password is wrong!\nPlease select an option."
                  "\n\t[1] Reinsert \n\t[2] Exit to Main Menu")
            opt = input("Enter your option: ")
            while opt not in ('1','2','3'):
                print("Invalid Input!")
                opt = input("Enter your option again: ")
            if opt == '2':
                flag = 0
    return continue_opt


def admin_function():
    flag = 1
    while flag == 1:
        print("\n\t*** REAL CHAMPIONS SPORT ACADEMY - Admin System ***\n\n"
              "Please select a function:\n\t 1.Add Record \n\t 2.Display Record \n\t 3.Search Specific Records \n"
              "\t 4.Sort and Display Record \n\t 5.Modify Record \n\t 6.Logout\n\t 7.Exit \n")
        opt = input("Enter the function number: ")
        while opt not in ('1','2','3','4','5','6','7'):
            print("Invalid Input!")
            opt = input("Enter the function number again: ")
        if opt == '1':
            add_function()
        elif opt == '2':
            display_function()
        elif opt == '3':
            search_function()
        elif opt == '4':
            sort_function()
        elif opt == '5':
            modify_function()
        elif opt == '6':
            flag = 0
            continue_opt = 1
            print("\n*** Logout... ***\n")
        else:
            check = input("Do you want to exit? 'Y' for YES, 'N' for NO: ")
            while check not in ('Y','y','N','n'):
                print("Invalid Input!")
                check = input("Do you want to exit? ( Y / N ): ")
            if check == 'Y' or check == 'y':
                flag = 0
                continue_opt = 0
    return continue_opt


def add_function():
    flag = 1
    while flag == 1:
        print("Select to add records of: \n\t 1.Coach \n\t 2.Sport \n\t 3.Sport Schedule \n\t 4.Back \n")
        opt = input("Enter your selection (1,2,3,4): ")
        while opt not in ('1','2','3','4'):
            print("Invalid Input!")
            opt = input("Enter your selection again (1,2,3,4): ")
        if opt == '1':
            coach_register_function()
        elif opt == '2':
            sport_register_function()
        elif opt == '3':
            sport_schedule_register_function()
        else:
            flag = 0


def coach_register_function():
    print("\n--- Coach Registration ---")
    continue_opt = 'Y'
    while continue_opt in ('Y','y'):
        myfile_r = open("data_file/coach_file.txt","r")
        myfile = open("data_file/coach_file.txt", "a")
        print("Please enter the following information")
        coach_name = input("Coach name: ")
        coach_DOB = input("Date of Birth(DD/MM/YYYY): ")
        date_joined = input("Date Joined (DD/MM/YYYY): ")
        date_terminated = " -- "
        sport_center = input("Sport Center: \n\t1. Bukit Jalil\t(SC-BJ) \n\t"
                             "2. Damansara\t(SC-DM)\n\t3. Cheras\t(SC-CR)""\nEnter the number : ")
        while sport_center not in ('1','2','3',):
            print("Invalid Input!")
            sport_center = input("Enter the number again: ")
        if sport_center == '1':
            sport_center = "Bukit Jalil (SC-BJ)"
            sc_code = "SC-BJ"
        elif sport_center == '2':
            sport_center = "Damansara (SC-DM)"
            sc_code = "SC-DM"
        elif sport_center == '3':
            sport_center = "Cheras (SC-CR)"
            sc_code = "SC-CR"
        text = 'Coaching Sport'
        coach_sport, code = sport_list(text)
        sport_code = sc_code+code
        hour_rate = input("Hourly Rate (RM100 - 500): RM ")
        while float(hour_rate) < 100 or float(hour_rate) > 500:
            print("Out of range!!!")
            hour_rate = input("Hourly Rate (RM100 - 500): RM ")
        rate = input("Rating (1.0 - 5.0): ")
        while float(rate) < 1.0 or float(rate) > 5.0:
            print("Out of range!!!")
            rate = input("Rating (1.0 - 5.0): ")
        mail = input("Email Address: ")
        phone = input("Contact Number: ")
        address = input("Address: ")
        id_num = 1
        for line in myfile_r:
            id_num += 1
        coach_id = "RC0" + str(100 + id_num)
        print("Please confirm the information:\n"
              "* Coach Name\t\t: " + coach_name + "\n* Date of birthday\t: " + coach_DOB + "\n* Date joined\t\t: " + date_joined +
              "\n* Date Terminated\t: " + date_terminated + "\n* Sport Center\t\t: " + sport_center + "\n* Coaching Sport\t: " + coach_sport +
              "\n* Sport Code\t\t: " + sport_code +"\n* Hourly rate\t\t: " + hour_rate + "\n* Rating\t\t: " + rate + "\n* Email address\t\t: " + mail +
              "\n* Contact Number\t: " + phone + "\n* Address\t\t: " + address)
        opt = input("Enter 'Y' to confirm, 'N' to cancel: ")
        while opt not in ('Y','y','N','n'):
            print("Invalid Input!")
            opt = input("Enter your selection again ( Y / N ): ")
        if opt == 'Y' or opt == 'y':
            myfile.write(coach_id + "\t" + coach_name + "\t" + coach_DOB + "\t" + date_joined + "\t" + date_terminated + "\t" + sport_center +
                         "\t" + coach_sport + "\t" + sport_code  + "\t" + hour_rate + "\t" + rate + "\t" + mail + "\t" + phone + "\t" + address + "\n")
            myfile.close()
            print("<<< Coach record successfully added >>>")
        else:
            print("<<< Coach record not added >>>")
        continue_opt = input("\nDo you want add another coach record? 'Y' to continue, 'N' to select add other record: ")
        while continue_opt not in ('Y','y','N','n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def sport_list(text):
    print(text)
    print("\t[1] Swimming\t[2] Badminton\t[3] Football\t[4] Archery\t[5] Gymnastics\n"
          "\t[6] Volleyball\t[7] Basketball\t[8] Cricket\t[9] Tennis\t[10] Table Tennis")
    opt = input("Enter the sport number: ")
    while int(opt) not in range(1,11):
        print("Invalid Input!")
        opt = input("Enter the sport number again: ")
    if opt == '1':
        opt = "Swimming"
        code = "01"
    elif opt == '2':
        opt = "Badminton"
        code = "02"
    elif opt == '3':
        opt = "Football"
        code = "03"
    elif opt == '4':
        opt = "Archery"
        code = "04"
    elif opt == '5':
        opt = "Gymnastics"
        code = "05"
    elif opt == '6':
        opt = "Volleyball"
        code = "06"
    elif opt == '7':
        opt = "Basketball"
        code = "07"
    elif opt == '8':
        opt = "Cricket"
        code = "08"
    elif opt == '9':
        opt = "Tennis"
        code = "09"
    else:
        opt = "Table Tennis"
        code = "010"
    return opt,code


def sport_register_function():
    print("\n--- Sport Registration ---")
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        flag = 0
        while flag == 0:
            print("Please enter the following information:")
            sport_center = input(
                "1. Select the Sport Center of the adding sport: \n\t1. Bukit Jalil\t(SC-BJ) \n\t2. Damansara\t(SC-DM)\n\t3. Cheras\t(SC-CR)"
                "\nEnter the number : ")
            while sport_center not in ('1','2','3'):
                print("Invalid Input!")
                sport_center = input("Enter the number again: ")
            if sport_center == '1':
                sport_center = "Bukit Jalil (SC-BJ)"
                sc_code = "SC-BJ"
            elif sport_center == '2':
                sport_center = "Damansara (SC-DM)"
                sc_code = "SC-DM"
            elif sport_center == '3':
                sport_center = "Cheras (SC-CR)"
                sc_code = "SC-CR"
            text = "2. Sport: "
            sport,code = sport_list(text)
            sport_code = sc_code+code
            x = 0
            sport_file_r = open("data_file/sport_file.txt","r")
            for line in sport_file_r:
                line = line.rstrip()
                if sport_code in line:
                    x = 1
            if x == 1:
                print("Sport record already esxit! Cannot add this sport.")
                break
            print("Available Coach: ")
            coach_file = open("data_file/coach_file.txt","r")
            for line in coach_file:
                line = line.rstrip()
                if sport_code in line:
                    print("\t" + line.split('\t')[1])
                    x = 1
            if x == 0:
                print("\tNot coach available! Need a coach to add this sport")
                break
            check = 1
            x = 0
            while check == 1:
                sport_coach = input("3. Head Coach of the sport: ")
                coach_file = open("data_file/coach_file.txt","r")
                for line in coach_file:
                    line = line.rstrip()
                    if sport_coach == line.split('\t')[1] and sport_code == line.split('\t')[7]:
                        x = 1
                if x == 1:
                    check = 0
                else:
                    print("Coach not found / Coach not available in this sport center or sport!")
                    opt = input("Select an option:\n\t[1] Reinsert Coach\n\t[2] Cancel add sport\nEnter Selection: ")
                    while opt != "1" and opt != '2':
                        opt = input("Enter Selection again: ")
                    if opt == '2':
                        check = 0
                        flag = 1
            if flag == 0:
                print("Please confirm the information:\n"
                      "* Sport Center\t: "+sport_center+"\n* Sport\t\t: "+sport+"\n* Sport Code\t: " + sport_code+"\n* Head Coach\t: "+sport_coach)
                opt = input("Enter 'Y' to confirm, 'N' to reinsert: ")
                while opt not in ('Y', 'y', 'N', 'n'):
                    print("Invalid Input!")
                    opt = input("Enter your selection again ( Y / N ): ")
                if opt == 'Y' or opt == 'y':
                    sport_file = open("data_file/sport_file.txt", "a")
                    sport_file.write(sport_center + "\t" + sport + "\t" + sport_code + "\t" + sport_coach + "\n")
                    sport_file.close()
                    print("<<< Sport record successful add >>>")
                    flag = 1
                else:
                    print("<<< Sport record not add >>>")
                    flag = 1
        continue_opt = input("\nDo you want add another sport? 'Y' to continue, 'N' to select add other record: ")
        while continue_opt not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def sport_schedule_register_function():
    print("\n--- Sport Schedule Registration ---")
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        flag = 0
        while flag == 0:
            myfile = open("data_file/sport_schedule.txt", "a")
            sport_file = open("data_file/sport_file.txt","r")
            print("Please enter the following information")
            sport_center = input("Select the Sport Center: \n\t1. Bukit Jalil\t(SC-BJ) \n\t2. Damansara\t(SC-DM)\n\t"
                                 "3. Cheras\t(SC-CR)""\nEnter the number : ")
            while sport_center not in ('1', '2', '3'):
                print("Invalid Input!")
                sport_center = input("Enter the number again: ")
            if sport_center == '1':
                sport_center = "Bukit Jalil (SC-BJ)"
                sc_code = "SC-BJ"
            elif sport_center == '2':
                sport_center = "Damansara (SC-DM)"
                sc_code = "SC-DM"
            elif sport_center == '3':
                sport_center = "Cheras (SC-CR)"
                sc_code = "SC-CR"
            text = "Sport: "
            sport,code = sport_list(text)
            sport_code = sc_code+code
            x = 0
            for line in sport_file:
                line = line.rstrip()
                if sport_code in line:
                    x = 1
            if x == 0:
                print("Sport record not esxit! Cannot add the sport schedule.")
                break
            day = input("Day of week (Mon,Tue,Wed,Thus,Fri,Sat,Sun): ")
            while day not in ('Mon','Tue','Wed','Thus','Fri','Sat','Sun'):
                print("Input not available!")
                sport_center = input("Day of week (Mon,Tue,Wed,Thus,Fri,Sat,Sun): ")
            st_time = input("Start Time (AM/PM): ")
            end_time = input("End Time (AM/PM): ")
            duration = input("Duration (How many hours): ")
            print("Please confirm the information:\n"
                  "* Sport Center\t: " + sport_center + "\n* Sport\t\t: " + sport + "\n* Sport Code\t: " + sport_code +
                  "\n* Day of week\t: " + day + "\n* Time\t\t: " + st_time + " - " + end_time +
                  "\n* Duration\t: " + duration + " hours")
            opt = input("Enter 'Y' to confirm, 'N' to reinsert: ")
            while opt not in ('Y', 'y', 'N', 'n'):
                print("Invalid Input!")
                opt = input("Enter your selection again ( Y / N ): ")
            if opt == 'Y' or opt == 'y':
                myfile.write(sport_center + "\t" + sport + "\t" + sport_code + "\t" + day + "\t" + st_time + " - " + end_time + "\t" + duration + "\n")
                myfile.close()
                print("<<< Sport Schedule successfully added >>>")
                flag = 1
            else:
                    print("<<< Sport Schedule not add >>>")
                    flag = 1
        continue_opt = input("\nDo you want add another sport schedule? 'Y' to continue, 'N' to select add other record: ")
        while continue_opt not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def display_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        print("Select to display all records of: \n\t 1.Coach \n\t 2.Sport \n\t 3.Register Student records \n\t 4.Student's Feedback\n\t 5.Back \n")
        opt = input("Enter your selection (1,2,3,4,5): ")
        while opt not in ('1','2','3','4','5'):
            print("Invalid Input!")
            opt = input("Enter your selection again (1,2,3,4,5): ")
        flag = 1
        if opt == '1':
            print("Coach ID\tName"+" "*16+"\tBirthday  \tJoined    \tTerminated\tSport Center        \tSport        Sport Code  Hourly Rate\tRating\tEmail"+" "*20+"\tContact Number\tAddress"
                  "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            myfile = open("data_file/coach_file.txt", "r")
            for line in myfile:
                data = line.rstrip().split('\t')
                print(data[0]+" "*2+"\t"+data[1]+" "*(20-len(data[1]))+"\t"+data[2]+"\t"+data[3]+"\t"+data[4]+" "*(10-len(data[4]))+
                      "\t"+data[5]+" "*(20-len(data[5]))+"\t"+data[6]+" "*(13-len(data[6]))+data[7]+" "*(12-len(data[7]))+"RM"+data[8]+" "*(9-len(data[8]))+
                      "\t"+data[9]+" "*(6-len(data[9]))+"\t"+data[10]+" "*(25-len(data[10]))+"\t"+data[11]+" "*(14-len(data[11]))+"\t"+data[12])
        elif opt == '2':
            print("Sport Center        \tSport       \tSport Code\tCoach"
                  "\n-----------------------------------------------------------------------")
            myfile = open("data_file/sport_file.txt", "r")
            for line in myfile:
                data = line.rstrip().split('\t')
                print(data[0]+" "*(20-len(data[0]))+"\t"+data[1]+" "*(12-len(data[1]))+"\t"+data[2]+" "*(10-len(data[2]))+"\t"+data[3])
        elif opt == '3':
            print("Student ID\tName" + " " * 16 + "\tGender\tBirthday  \tSport Center        \tSport       \tSport Code\tContact Number\tAddress" + " " * 28 +"\tEmail"
                  "\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            myfile = open("data_file/student_file.txt", "r")
            for line in myfile:
                data = line.rstrip().split('\t')
                print(data[0] + " " * (10 - len(data[0])) + "\t" + data[1] + " " * (20 - len(data[1])) + "\t" + data[2] + " " * (6 - len(data[2])) +
                      "\t" + data[3] + " " * (10 - len(data[3])) + "\t" + data[4] + " " * (20 - len(data[4])) +"\t" + data[5] + " " * (12 - len(data[5])) +
                      "\t" + data[6] + " " * (10 - len(data[6])) +"\t" + data[7] + " " * (14 - len(data[7])) + "\t" + data[8] + " " * (35 - len(data[8]))+
                      "\t" + data[9] + " " * (25 - len(data[9])))
        elif opt == '4':
            print("Coach ID\tName"+" "*16+"\tStudent's Feedback"
                  "\n-------------------------------------------------------------")
            myfile = open("data_file/coach_feedback.txt", "r")
            for line in myfile:
                data = line.rstrip().split('\t')
                print(data[0]+" "*2+"\t"+data[1]+" "*(20-len(data[1]))+"\t"+data[2])
        else:
            flag = 0
            continue_opt = 'N'
        if flag == 1:
            continue_opt = input("\nDo you want to continue? 'Y' to continue, 'N' back to Admin System: ")
            while continue_opt not in ('Y', 'y', 'N', 'n'):
                print("Invalid Input!")
                continue_opt = input("Enter your selection again ( Y / N ): ")


def search_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        print("Select to search specific records of: \n\t[1] Coach by Coach ID\n\t[2] Coach by overall performance (Rating)"
              "\n\t[3] Sport by Sport ID\n\t[4] Student by Student ID \n\t[5] Back\n")
        opt = input("Enter your selection (1,2,3,4,5): ")
        while opt not in ('1','2','3','4','5'):
            print("Invalid Input!")
            opt = input("Enter your selection again (1,2,3,4,5): ")
        flag = 1
        if opt == '1':
            coach_id = input("Enter Coach ID: ")
            print("Coach ID\tName" + " " * 18 + "\tBirthday  \tJoined    \tTerminated\tSport Center        \tSport      Sport Code  Hourly Rate\tRating\tEmail" + " " * 20 + "\tConnect Number\tAddress" + " " * 23 +
                  "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            myfile = open("data_file/coach_file.txt", "r")
            check = 0
            for line in myfile:
                line = line.rstrip()
                if coach_id == line.split('\t')[0]:
                    data = line.split('\t')
                    print(data[0] + " " * 2 + "\t" + data[1] + " " * (20 - len(data[1])) + "\t" + data[2] + "\t" +data[3] + "\t" + data[4] + " " * (10 - len(data[4])) +
                          "\t"+data[5]+" "*(20-len(data[5]))+"\t"+data[6]+" "*(12-len(data[6]))+data[7]+" "*(12-len(data[7]))+"RM"+data[8]+" "*(9-len(data[8]))+
                          "\t"+data[9]+" "*(6-len(data[9]))+"\t"+data[10]+" "*(25-len(data[10]))+"\t"+data[11]+" "*(14-len(data[11]))+"\t"+data[12])
                    check = 1
            print("\nStudent's Feedback: ")
            myfile = open("data_file/coach_feedback.txt", "r")
            for line in myfile:
                line = line.rstrip()
                if coach_id == line.split('\t')[0]:
                    data = line.split('\t')
                    print("* "+data[2])
            if check == 0:
                print("Coach ID not found!")
        elif opt == '2':
            rate = input("Enter the Rating (1.0-5.0): ")
            while float(rate) < 1.0 or float(rate) > 5.0:
                print("Out of range!")
                rate = input("Enter the Rating Again (1-5): ")
            print("Coach ID\tName" + " " * 18 + "\tBirthday  \tJoined    \tTerminated\tSport Center        \tSport        Sport Code  Hourly Rate\tRating\tEmail" + " " * 20 + "\tConnect Number\tAddress" + " " * 23 +
                  "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            myfile = open("data_file/coach_file.txt", "r")
            check = 0
            for line in myfile:
                line = line.rstrip()
                if rate == line.split('\t')[9]:
                    data = line.split('\t')
                    print(data[0] + " " * 2 + "\t" + data[1] + " " * (20 - len(data[1])) + "\t" + data[2] + "\t" +data[3] + "\t" + data[4] + " " * (10 - len(data[4])) +
                          "\t"+data[5]+" "*(20-len(data[5]))+"\t"+data[6]+" "*(13-len(data[6]))+data[7]+" "*(12-len(data[7]))+"RM"+data[8]+" "*(9-len(data[8]))+
                          "\t"+data[9]+" "*(6-len(data[9]))+"\t"+data[10]+" "*(25-len(data[10]))+"\t"+data[11]+" "*(14-len(data[11]))+"\t"+data[12])
                    check = 1
            if check == 0:
                print("Rating not found!")
        elif opt == '3':
            sport_id = input("Enter the Sport ID: ")
            print("Sport Center        \tSport       \tSport Code\tCoach"
                  "\n------------------------------------------------------------------------")
            myfile = open("data_file/sport_file.txt", "r")
            check = 0
            for line in myfile:
                line = line.rstrip()
                if sport_id == line.split('\t')[2]:
                    data = line.split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t"+data[1] + " "*(12-len(data[1])) + "\t"+data[2] + " "*(10-len(data[2]))+ "\t" + data[3])
                    check = 1
            if check == 0:
                print("Sport ID not found!")
        elif opt == '4':
            student_id = input("Enter the Student ID: ")
            print("Student ID\tName" + " " * 18 + "\tGender\tBirthday  \tSport Center        \tSport       |tSport Code\tContact Number\tAddress" + " " * 28 + "\tEmail"
                  "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            myfile = open("data_file/student_file.txt", "r")
            check = 0
            for line in myfile:
                line = line.rstrip()
                if student_id == line.split('\t')[0]:
                    data = line.split('\t')
                    print(data[0] + " " * (10 - len(data[0])) + "\t" + data[1] + " " * (20 - len(data[1])) + "\t" + data[2] + " " * (6 - len(data[2])) +
                          "\t" + data[3] + " " * (10 - len(data[3])) + "\t" + data[4] + " " * (20 - len(data[4])) + "\t" + data[5] + " " * (12 - len(data[5])) +
                          "\t" + data[6] + " " * (10 - len(data[6])) +"\t" + data[7] + " " * (14 - len(data[7])) + "\t" + data[8] + " " * (35 - len(data[8]))+
                          "\t" + data[9] + " " * (25 - len(data[9])))
                    check = 1
            if check == 0:
                print("Student ID not found!")
        else:
            flag = 0
            continue_opt = 'N'
        if flag == 1:
            continue_opt = input("\nDo you want to continue? 'Y' to continue, 'N' back to Admin System: ")
            while continue_opt not in ('Y', 'y', 'N', 'n'):
                print("Invalid Input!")
                continue_opt = input("Enter your selection again ( Y / N ): ")


def sort_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        mylist = []
        myfile = open("data_file/coach_file.txt", "r")
        print("Select to sort records by: \n\t 1.Coaches in ascending order by names \n\t 2.Coaches Hourly Pay Rate in ascending order "
              "\n\t 3.Coaches Overall Performance in ascending order \n\t 4. Back \n")
        opt = input("Enter your selection (1,2,3,4): ")
        while opt not in ('1','2','3','4'):
            print("Invalid Input!")
            opt = input("Enter your selection again (1,2,3,4): ")
        flag = 1
        if opt == '1':
            print("Coach ID\tName" + " " * 18 + "\tBirthday  \tJoined    \tTerminated\tSport Center        \tSport       Sport Code  Hourly Rate\tRating\tEmail" + " " * 20 + "\tContact Number\tAddress"
                  "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            for lines in myfile:
                line = lines.rstrip()
                mylist.append(line)
            for i in range(0, len(mylist)):
                for j in range(i + 1, len(mylist)):
                    if mylist[i].split("\t")[1].lower() > mylist[j].split('\t')[1].lower():
                        temp = mylist[i]
                        mylist[i] = mylist[j]
                        mylist[j] = temp
            for data in mylist:
                data = data.split("\t")
                print(data[0] + " " * 2 + "\t" + data[1] + " " * (20 - len(data[1])) + "\t" + data[2] + "\t" + data[3] + "\t" + data[4] + " " * (10 - len(data[4])) +
                      "\t"+data[5]+" "*(20-len(data[5]))+"\t"+data[6]+" "*(13-len(data[6]))+data[7]+" "*(12-len(data[7]))+"RM"+data[8]+" "*(9-len(data[8]))+
                      "\t"+data[9]+" "*(6-len(data[9]))+"\t"+data[10]+" "*(25-len(data[10]))+"\t"+data[11]+" "*(14-len(data[11]))+"\t"+data[12])
        elif opt == '2':
            print("Coach ID\tName" + " " * 18 + "\tBirthday  \tJoined    \tTerminated\tSport Center        \tSport       Sport Code  Hourly Rate\tRating\tEmail" + " " * 20 + "\tContact Number\tAddress"
                  "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            for lines in myfile:
                line = lines.rstrip()
                mylist.append(line)
            for i in range(0, len(mylist)):
                for j in range(i + 1, len(mylist)):
                    if mylist[i].split("\t")[8] > mylist[j].split('\t')[8]:
                        temp = mylist[i]
                        mylist[i] = mylist[j]
                        mylist[j] = temp
            for data in mylist:
                data = data.split("\t")
                print(data[0] + " " * 2 + "\t" + data[1] + " " * (20 - len(data[1])) + "\t" + data[2] + "\t" + data[3] + "\t" + data[4] + " " * (10 - len(data[4])) +
                      "\t"+data[5]+" "*(20-len(data[5]))+"\t"+data[6]+" "*(13-len(data[6]))+data[7]+" "*(12-len(data[7]))+"RM"+data[8]+" "*(9-len(data[8]))+
                      "\t"+data[9]+" "*(6-len(data[9]))+"\t"+data[10]+" "*(25-len(data[10]))+"\t"+data[11]+" "*(14-len(data[11]))+"\t"+data[12])
        elif opt == '3':
            print("Coach ID\tName" + " " * 18 + "\tBirthday  \tJoined    \tTerminated\tSport Center        \tSport       Sport Code  Hourly Rate\tRating\tEmail" + " " * 20 + "\tContact Number\tAddress"
                  "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            for lines in myfile:
                line = lines.rstrip()
                mylist.append(line)
            for i in range(0, len(mylist)):
                for j in range(i + 1, len(mylist)):
                    if mylist[i].split("\t")[9] > mylist[j].split('\t')[9]:
                        temp = mylist[i]
                        mylist[i] = mylist[j]
                        mylist[j] = temp
            for data in mylist:
                data = data.split("\t")
                print(data[0] + " " * 2 + "\t" + data[1] + " " * (20 - len(data[1])) + "\t" + data[2] + "\t" + data[3] + "\t" + data[4] + " " * (10 - len(data[4])) +
                      "\t"+data[5]+" "*(20-len(data[5]))+"\t"+data[6]+" "*(13-len(data[6]))+data[7]+" "*(12-len(data[7]))+"RM"+data[8]+" "*(9-len(data[8]))+
                      "\t"+data[9]+" "*(6-len(data[9]))+"\t"+data[10]+" "*(25-len(data[10]))+"\t"+data[11]+" "*(14-len(data[11]))+"\t"+data[12])
        else:
            flag = 0
            continue_opt = 'N'
        if flag == 1:
            continue_opt = input("\nDo you want to continue? 'Y' to continue, 'N' back to Admin System: ")
            while continue_opt not in ('Y', 'y', 'N', 'n'):
                print("Invalid Input!")
                continue_opt = input("Enter your selection again ( Y / N ): ")


def modify_function():
    flag = 1
    while flag == 1:
        print("Select to modify records of: \n\t 1.Coach \n\t 2.Sport \n\t 3.Sport Schedule \n\t 4.Back \n")
        opt = input("Enter your selection (1,2,3,4): ")
        while opt not in ('1','2','3','4'):
            print("Invalid Input!")
            opt = input("Enter your selection again (1,2,3,4): ")
        if opt == '1':
            coach_modify_function()
        elif opt == '2':
            sport_modify_function()
        elif opt == '3':
            sport_schedule_modify_function()
        else:
            flag = 0


def coach_modify_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        file_list = []
        opt = input("\nSelect the modify option: \n\t[1] Date Terminated\n\t[2] Contact Number\n\t[3] Address\n\t"
                    "[4] Email\nEnter your selection: ")
        while opt not in ('1','2','3','4'):
            print("Invalid Input!")
            opt = input("Enter your selection again: ")
        coach = input("Enter the coach name/ID: ")
        check = 0
        while check == 0:
            myfile = open("data_file/coach_file.txt", "r")
            for line in myfile:
                line = line.rstrip()
                if coach == line.split('\t')[0] or coach == line.split('\t')[1]:
                    check = 1
            if check == 0:
                print("Coach not found!")
                coach = input("Enter the coach name/ID again: ")
        myfile = open("data_file/coach_file.txt", "r")
        if opt == '1':
            for line in myfile:
                line = line.rstrip()
                if coach in line:
                    print("Coach ID\t: " + line.split('\t')[0]+"\nCoach Name\t: "+line.split('\t')[1]+"\nDate Terminated\t\t: "+ line.split('\t')[4])
                    changelist = line.split('\t')
                    changelist[4] = input("Enter Date Terminated: ")
                    new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2]+ "\t" + changelist[3]+ "\t" + \
                                changelist[4]+ "\t" + changelist[5]+ "\t" + changelist[6]+ "\t" + changelist[7]+ "\t" + \
                                changelist[8]+ "\t" + changelist[9]+ "\t" + changelist[10]+ "\t" + changelist[11]+ "\t" + changelist[12]
                    file_list.append(new_lines)
                else:
                    file_list.append(line)
        elif opt == '2':
            for line in myfile:
                line = line.rstrip()
                if coach in line:
                    print("Coach ID\t\t: " + line.split('\t')[0] + "\nCoach Name\t\t: " + line.split('\t')[1] + "\nContact Number\t\t: "+ line.split('\t')[11])
                    changelist = line.split('\t')
                    changelist[11] = input("Enter new contact number: ")
                    new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                                changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                                changelist[8] + "\t" + changelist[9] + "\t" + changelist[10] + "\t" + changelist[11]+ "\t" + changelist[12]
                    file_list.append(new_lines)
                else:
                    file_list.append(line)
        elif opt == '3':
            for line in myfile:
                line = line.rstrip()
                if coach in line:
                    print("Coach ID\t: " + line.split('\t')[0] + "\nCoach Name\t: " + line.split('\t')[1] + "\nAddress\t\t: " + line.split('\t')[12])
                    changelist = line.split('\t')
                    changelist[12] = input("Enter new address: ")
                    new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                                changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                                changelist[8] + "\t" + changelist[9] + "\t" + changelist[10] + "\t" + changelist[11]+ "\t" + changelist[12]
                    file_list.append(new_lines)
                else:
                    file_list.append(line)
        elif opt == '4':
            for line in myfile:
                line = line.rstrip()
                if coach in line:
                    print("Coach ID\t: " + line.split('\t')[0] + "\nCoach Name\t: " + line.split('\t')[1] + "\n Email\t\t: " + line.split('\t')[10])
                    changelist = line.split('\t')
                    changelist[10] = input("Enter new email: ")
                    new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                                changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                                changelist[8] + "\t" + changelist[9] + "\t" + changelist[10] + "\t" + changelist[11]+ "\t" + changelist[12]
                    file_list.append(new_lines)
                else:
                    file_list.append(line)
        confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
        while confirm not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
        if confirm in ('Y','y'):
            myfile = open("data_file/coach_file.txt", "w")
            for data in file_list:
                myfile.write(data + "\n")
            myfile.close()
            print("--- Successfully modify record ---")
        else:
            print("--- Record not change ---")
        continue_opt = input("\nDo you want to continue modify? 'Y' for YES, 'N' for NO: ")
        while continue_opt not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def sport_modify_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        file_list = []
        opt = input("\nSelect the modify option: \n\t[1] Head Coach of sport\nEnter your selection: ")
        while opt != '1':
            print("Invalid Input!")
            opt = input("Enter your selection again: ")
        sport_code = input("Enter the Sport Code: ")
        check = 0
        while check == 0:
            myfile = open("data_file/sport_file.txt", "r")
            for line in myfile:
                line = line.rstrip()
                if sport_code == line.split('\t')[2]:
                    check = 1
            if check == 0:
                print("Sport record not found!")
                sport_code = input("Enter Sport Code again: ")
        flag = 1
        myfile = open("data_file/sport_file.txt", "r")
        for line in myfile:
            line = line.rstrip()
            if sport_code == line.split('\t')[2]:
                print("* Sport Code\t: " + line.split('\t')[2]+"\n* Sport\t\t: "+line.split('\t')[1]+"\n* Head Coach\t: "+ line.split('\t')[3])
                changelist = line.split('\t')
                print("Available Coach: ")
                coach_file = open("data_file/coach_file.txt","r")
                for line in coach_file:
                    line = line.rstrip()
                    if sport_code in line:
                        print("\t" + line.split('\t')[1])
                while check == 1:
                    changelist[3] = input("Enter New Head Coach: ")
                    x = 0
                    coach_file = open("data_file/coach_file.txt","r")
                    for line in coach_file:
                        line = line.rstrip()
                        if changelist[3] == line.split('\t')[1] and sport_code == line.split('\t')[7]:
                            x = 1
                    if x == 1:
                        check = 0
                    else:
                        print("Coach not found / Coach not available in this sport center or sport!")
                        opt = input("Select an option:\n\t[1] Reinsert Coach\n\t[2] Cancel add sport\nEnter Selection: ")
                        while opt != "1" and opt != '2':
                            print("Invalid Input")
                            opt = input("Enter Selection again: ")
                        if opt == '2':
                            check = 0
                            flag = 0
                new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2]+ "\t" + changelist[3]
                file_list.append(new_lines)
            else:
                file_list.append(line)
        if flag == 1:
            confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
            while confirm not in ('Y', 'y', 'N', 'n'):
                print("Invalid Input!")
                confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
            if confirm in ('Y','y'):
                myfile = open("data_file/sport_file.txt", "w")
                for data in file_list:
                    myfile.write(data + "\n")
                myfile.close()
                print("--- Successfully modify record ---")
            else:
                print("--- Record not change ---")
        continue_opt = input("\nDo you want to continue modify? 'Y' for YES, 'N' for NO: ")
        while continue_opt not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def sport_schedule_modify_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        myfile = open("data_file/sport_schedule.txt", "r")
        file_list = []
        sport_code = input("Enter the Sport Code: ")
        check = 0
        while check == 0:
            for line in myfile:
                line = line.rstrip()
                if sport_code in line:
                    check = 1
            if check == 0:
                print("Sport not found!")
                sport_code = input("Enter the Sport Code again: ")
        myfile = open("data_file/sport_schedule.txt", "r")
        for line in myfile:
            line = line.rstrip()
            if sport_code in line:
                print("Sport\t\t\t: "+line.split('\t')[1]+"\nSport Code\t: " + line.split('\t')[2]+"\nDay of week\t: "+ line.split('\t')[3]+
                      "\nTime\t\t\t: "+ line.split('\t')[4]+"\nDuration\t\t: "+ line.split('\t')[5])
                changelist = line.split('\t')
                changelist[3] = input("Enter New Day of Week(Mon,Tue,Wed,Thus,Fri,Sat,Sun): ")
                while changelist[3] not in ('Mon', 'Tue', 'Wed', 'Thus', 'Fri', 'Sat', 'Sun'):
                    print("Input not available!")
                    changelist[3] = input("Enter New Day of Week(Mon,Tue,Wed,Thus,Fri,Sat,Sun): ")
                st_time = input("New Start Time (AM/PM): ")
                end_time = input("New End Time (AM/PM): ")
                changelist[4] = st_time + " - " + end_time
                changelist[5] = input("Duration: ")
                new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + changelist[4] + "\t" + changelist[5]
                file_list.append(new_lines)
            else:
                file_list.append(line)
        confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
        while confirm not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
        if confirm in ('Y','y'):
            myfile = open("data_file/sport_schedule.txt", "w")
            for data in file_list:
                myfile.write(data + "\n")
            myfile.close()
            print("--- Successfully modify record ---")
        else:
                print("--- Record not change ---")
        continue_opt = input("\nDo you want to continue modify? 'Y' for YES, 'N' for NO: ")
        while continue_opt not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def student_function():
    flag = 1
    while flag == 1:
        print("\n\t*** REAL CHAMPIONS SPORT ACADEMY - Student System ***\n")
        print("Please select a function:\n\t[1] View Details of: \n\t\t* Sport\n\t\t* Sport Schedule \n\t[2] Login \n"
              "\t[3] New student? Create An Account \n\t[4] Exit\n")
        opt = input("Enter your selection: ")
        while opt not in ('1','2','3','4'):
            print("Invalid Input!")
            opt = input("Enter your selection again: ")
        if opt == '1':
            student_view_function()
        elif opt == '2':
            continue_opt = student_login_function()
            flag = 0
        elif opt == '3':
            flag,continue_opt = student_register_function()
        else:
            opt = input("Do you want to exit? 'Y' for YES, 'N' for NO: ")
            while opt not in ('Y','y','N','n'):
                print("Invalid Input!")
                opt = input("Do you want to exit? ( Y / N ): ")
            if opt == 'Y' or opt == 'y':
                print("\n*** Exit... ***")
                flag = 0
                continue_opt = 0
    return continue_opt


def student_view_function():
    flag = 1
    while flag == 1:
        print("Please select a specific categories to view detail: \n\t[a] Sport \n\t[b] Sport Schedule\n\t[1] Back\n")
        opt_view = input("Enter your selection: ")
        while opt_view not in ('1', 'A', 'a', 'B', 'b'):
            print("Invalid Input!")
            opt_view = input("Enter your selection again: ")
        if opt_view == 'A' or opt_view == 'a':
            sport_detail_function()
        elif opt_view == 'B' or opt_view == 'b':
            sport_schedule_detail_function()
        else:
            flag = 0


def sport_detail_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        myfile = open("data_file/sport_file.txt","r")
        sport_center = input("Select the Sport Center to view sport detail: \n\t1. Bukit Jalil\n\t2. Damansara\n\t3. Cheras\nEnter the number: ")
        while sport_center not in ('1','2','3'):
            sport_center = input("Invalid input!\nPlease enter the number again: ")
        print("Sport Center(Code)  \tSport       \tSport Code\tCoach"
              "\n-------------------------------------------------------------------------------")
        if sport_center == '1':
            sport_center = 'Bukit Jalil (SC-BJ)'
            for line in myfile:
                line = line.rstrip()
                if sport_center in line:
                    data = line.rstrip().split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t"+data[1] + " "*(12-len(data[1])) + "\t" + data[2] + " "*(10-len(data[2]))+ "\t" + data[3])
        elif sport_center == '2':
            sport_center = 'Damansara (SC-DM)'
            for line in myfile:
                line = line.rstrip()
                if sport_center in line:
                    data = line.rstrip().split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t"+data[1] + " "*(12-len(data[1])) + "\t" + data[2] + " "*(10-len(data[2])) + "\t" + data[3])
        else:
            sport_center = 'Cheras (SC-CR)'
            for line in myfile:
                line = line.rstrip()
                if sport_center in line:
                    data = line.rstrip().split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t"+data[1] + " "*(12-len(data[1])) + "\t" + data[2] + " "*(10-len(data[2])) + "\t" + data[3])
        continue_opt = input("Do you want to continue to view others sport? 'Y' for YES, 'N' for NO : ")
        while continue_opt not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def sport_schedule_detail_function():
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        myfile = open("data_file/sport_schedule.txt","r")
        sport_center = input("Select the Sport Center to view sport schedule: \n\t1. Bukit Jalil\n\t2. Damansara\n\t3. Cheras\nEnter the number: ")
        while sport_center not in ('1','2','3'):
            sport_center = input("Invalid input!\nPlease enter the number again: ")
        print("Sport Center(Code)  \tSport       \tSport Code\tDay of week\tTime     \tDuration (hrs)"
              "\n-------------------------------------------------------------------------------------------------")
        if sport_center == '1':
            sport_center = 'Bukit Jalil (SC-BJ)'
            for line in myfile:
                line = line.rstrip()
                if sport_center in line:
                    data = line.rstrip().split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t" + data[1] + " " * (12 - len(data[1])) +"\t" + data[2] + " " * (10 - len(data[2])) +"\t" +
                          data[3] + " " * (11 - len(data[3])) + "\t" + data[4] + " " * (9 - len(data[4])) + "\t" + data[5])
        elif sport_center == '2':
            sport_center = 'Damansara (SC-DM)'
            for line in myfile:
                line = line.rstrip()
                if sport_center in line:
                    data = line.rstrip().split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t" + data[1] + " " * (12 - len(data[1])) +"\t" + data[2] + " " * (10 - len(data[2])) +"\t" +
                          data[3] + " " * (11 - len(data[3])) + "\t" + data[4] + " " * (9 - len(data[4])) + "\t" + data[5])
        else:
            sport_center = 'Cheras (SC-CR)'
            for line in myfile:
                line = line.rstrip()
                if sport_center in line:
                    data = line.rstrip().split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t" + data[1] + " " * (12 - len(data[1])) +"\t" + data[2] + " " * (10 - len(data[2])) +"\t" +
                          data[3] + " " * (11 - len(data[3])) + "\t" + data[4] + " " * (9 - len(data[4])) + "\t" + data[5])
        continue_opt = input("Do you want to continue to view others sport schedule? 'Y' for YES, 'N' for NO : ")
        while continue_opt not in ('Y', 'y', 'N', 'n'):
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def student_login_function():
    print("\n\t*** Student Login ***\n")
    flag = 1
    while flag == 1:
        student_id = input("Student ID / Email: ")
        student_pass = input("Password: ")
        myfile = open("data_file/student_file.txt","r")
        x = 0
        for line in myfile:
            line = line.rstrip()
            if student_id and student_pass in line:
                student_list = line.split('\t')
                x = 1
        if x == 1:
            print("\n\t*** Login Successful! ***")
            continue_opt = registered_student_function(student_list)
            flag = 0
        else:
            print("User not found! Your Student ID or password is wrong!\nPlease select an option."
                  "\n\t[1] Reinsert \n\t[2] Exit")
            opt = input("Enter your option: ")
            while opt not in ('1','2'):
                print("Invalid Input!")
                opt = input("Enter your option again: ")
            if opt == '2':
                flag = 0
                continue_opt = 1
    return continue_opt
        

def student_register_function():
    print("\n\t--- Student Registration ---\n")
    myfile_r = open("data_file/student_file.txt","r")
    myfile = open("data_file/student_file.txt", "a")
    print("Creating a new account.\nPlease enter the student info:")
    student_name = input("Student name: ")
    gender = input("Gender: [1] Male\n\t[2] Female\n\tEnter number: ")
    while gender not in ('1', '2'):
        print("Invalid Input!")
        gender = input("Enter number again: ")
    if gender == '1':
        gender = "Male"
    else:
        gender = "Female"
    student_DOB = input("Date of Birth(DD/MM/YYYY): ")
    student_sport_center = input("Sport Center: \n\t1. Bukit Jalil\t(SC-BJ) \n\t"
                                 "2. Damansara\t(SC-DM)\n\t3. Cheras\t(SC-CR)""\nEnter the number : ")
    while student_sport_center not in ('1', '2', '3'):
        print("Invalid Input!")
        student_sport_center = input("Enter the number again: ")
    if student_sport_center == '1':
        student_sport_center = "Bukit Jalil (SC-BJ)"
        sc_code = "SC-BJ"
    elif student_sport_center == '2':
        student_sport_center = "Damansara (SC-DM)"
        sc_code = "SC-DM"
    elif student_sport_center == '3':
        student_sport_center = "Cheras (SC-CR)"
        sc_code = "SC-CR"
    text = "Register Sport: "
    student_sport,code = sport_list(text)
    sport_code = sc_code+code
    phone = input("Contact Number: ")
    address = input("Address: ")
    print("---Login Data---")
    mail = input("Email Address: ")
    check = 1
    while check == 1:
        password = input("Password (at least 8 characters): ")
        while len(password) < 8:
            print("Invalid password")
            password = input("Password (at least 8 characters): ")
        confirm_pass = input("Confirm password. Please enter the password again: ")
        if confirm_pass != password:
            print("The password confirmation does not match! Please enter again.")
        else:
            check = 0
    id_num = 1
    for line in myfile_r:
        id_num += 1
        student_id = "RS0" + str(100 + id_num)
    confirm = input("Confirm to register account? 'Y' for YES, 'N' for NO: ")
    while confirm not in ('Y','y','N','n'):
            print("Invalid Input!")
            confirm = input("Enter your option again: ")
    if confirm in ('Y','y'):
        myfile.write(student_id + "\t" + student_name + "\t" + gender + "\t" + student_DOB + "\t" + student_sport_center
                     + "\t" + student_sport + "\t" + sport_code + "\t" + phone + "\t" + address + "\t" + mail + "\t" + password + "\n")
        myfile.close()
        print("<<< Account registration is successful！ >>>")
        continue_opt = student_login_function()
        flag = 0
    else:
        print("<<< Account registration is canceled！ >>>")
        flag = 1
        continue_opt = 1
    return flag, continue_opt


def registered_student_function(student_list):
    flag = 1
    while flag == 1:
        print("\n\t*** REAL CHAMPIONS SPORT ACADEMY - Registered Student System ***\n")
        print("Login as: \n\t* Student ID: "+ student_list[0] + "\n\t* Name\t: "+ student_list[1]+
              "\n----------------------------------------------------")
        print("Please select a function:\n\t[1] View Details of: \n\t\t* Sport\n\t\t* Sport Schedule\n\t\t* Coach\n\t\t* Self-Record\n\t\t"
              "* Registered Sport Schedule \n\t[2] Modify Self Record \n\t[3] Provide feedback and Star to Coach \n\t[4] Logout\n\t[5] Exit\n")
        opt = input("Enter your selection: ")
        while opt not in ('1', '2', '3','4','5'):
            print("Invalid Input!")
            opt = input("Enter your selection again: ")
        if opt == '1':
            regis_student_view_function(student_list)
        elif opt == '2':
            student_modify_function(student_list)
        elif opt == '3':
            feedback_star_function(student_list)
        elif opt == '4':
            flag = 0
            continue_opt = 1
            print("\n*** Logout... ***")
        else:
            opt = input("Do you want to exit? 'Y' for YES, 'N' for NO: ")
            while opt not in ('Y','y','N','n'):
                print("Invalid Input!")
                opt = input("Do you want to exit? ( Y / N ): ")
            if opt == 'Y' or opt == 'y':
                print("\n*** Exit... ***")
                flag = 0
                continue_opt = 0
    return continue_opt


def regis_student_view_function(student_list):
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        coach_file = open("data_file/coach_file.txt","r")
        sport_file = open("data_file/sport_file.txt","r")
        sport_schedule = open("data_file/sport_schedule.txt","r")
        print("Please select a specific categories to view detail: \n\t[a] Sport \n\t[b] Sport Schedule\n\t[c] Coach \n\t[d] Self-Record \n\t"
              "[e] Registered Sport Schedule \n\t[1] Back\n")
        opt_view = input("Enter your selection: ")
        while opt_view not in ('1', 'A', 'a', 'B', 'b','C','c','D','d','E','e'):
            print("Invalid Input!")
            opt_view = input("Enter your selection again: ")
        flag = 1
        if opt_view == 'A' or opt_view == 'a':
            sport_detail_function()
            flag = 0
        elif opt_view == 'B' or opt_view == 'b':
            sport_schedule_detail_function()
            flag = 0
        elif opt_view == 'C' or opt_view == 'c':
            coach = ""
            x = 0
            for line in sport_file:
                line = line.rstrip()
                if student_list[6] in line:
                    coach = line.split('\t')[3]
                    x = 1
            if x == 0:
                print("No coach to view")
                break
            for line in coach_file:
                line = line.rstrip()
                if coach in line:
                    data = line.split('\t')
                    print("* Coach Name\t\t: " + data[1] + "\n* Date of birthday\t: " + data[2] +
                          "\n* Sport Center\t\t: " + data[5] + "\n* Coaching Sports\t: " + data[6] + "\n* Sport Code\t\t\t: " + data[7] +
                          "\n* Hourly rate\t\t: " + data[8] + "\n* Rating\t\t: " + data[9] +
                          "\n* Email address\t\t: " + data[10] + "\n* Contact Number\t: " + data[11]+"\n")
        elif opt_view == 'D' or opt_view == 'd':
            print("* Student ID\t\t: " + student_list[0] + "\n* Name\t\t\t: " + student_list[1] + "\n* Gender\t\t: " + student_list[2] +
                  "\n* Date of birthday\t: " + student_list[3] + "\n* Sport Center\t\t: " + student_list[4] + "\n* Registered Sports\t: " + student_list[5] +
                  "\n* Sport Code\t: " + student_list[6] +"\n* Contact Number\t: " + student_list[7] + "\n* Address\t\t: " + student_list[8]+
                  "\n* Email\t\t\t: " + student_list[9])
        elif opt_view == 'E' or opt_view == 'e':
            print("Sport Center        \tSport       \tSport Code\tDay of week\tTime     \tDuration (hrs)"
                  "\n-------------------------------------------------------------------------------------------")
            for line in sport_schedule:
                line = line.rstrip()
                if student_list[6] in line:
                    data = line.rstrip().split('\t')
                    print(data[0] + " " * (20 - len(data[0])) + "\t" + data[1] + " " * (12 - len(data[1])) + "\t" + data[2] + " " * (10 - len(data[2])) +"\t" +
                          data[3] + " " * (11 - len(data[3])) + "\t" + data[4] + " " * (9 - len(data[4])) + "\t" + data[5])
        else:
            flag = 0
            continue_opt = 'N'
        if flag == 1:
            continue_opt = input("Do you want to continue? 'Y' to continue, 'N' back to Registered Student System: ")
            while continue_opt != 'Y' and continue_opt != 'y' and continue_opt != 'N' and continue_opt != 'n':
                print("Invalid Input!")
                continue_opt = input("Enter your selection again ( Y / N ): ")


def student_modify_function(student_list):
    continue_opt = 'Y'
    while continue_opt in ('Y', 'y'):
        myfile = open("data_file/student_file.txt", "r")
        file_list = []
        opt = input("\nSelect the modify option: \n\t[1] Contact Number\n\t[2] Address\n\t"
                    "[3] Email\n\t[4] Password\n\nEnter your selection: ")
        while opt not in ('1','2','3','4'):
            print("Invalid Input!")
            opt = input("Enter your selection again: ")
        check = 1
        if opt == '1':
            for line in myfile:
                line = line.rstrip()
                if student_list[0] in line:
                    changelist = line.split('\t')
                    print("Current contact number:"+student_list[7])
                    changelist[7] = input("Enter new contact number: ")
                    new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                                changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                                changelist[8] + "\t" + changelist[9] + "\t" + changelist[10]
                    file_list.append(new_lines)
                else:
                    file_list.append(line)
        elif opt == '2':
            for line in myfile:
                line = line.rstrip()
                if student_list[0] in line:
                    changelist = line.split('\t')
                    print("Current address:" + student_list[8])
                    changelist[8] = input("Enter new address: ")
                    new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                                changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                                changelist[8] + "\t" + changelist[9] + "\t" + changelist[10]
                    file_list.append(new_lines)
                else:
                    file_list.append(line)
        elif opt == '3':
            for line in myfile:
                line = line.rstrip()
                if student_list[0] in line:
                    changelist = line.split('\t')
                    print("Current email:" + student_list[9])
                    changelist[9] = input("Enter new email: ")
                    new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                                changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                                changelist[8] + "\t" + changelist[9] + "\t" + changelist[10]
                    file_list.append(new_lines)
                else:
                    file_list.append(line)
        elif opt == '4':
            for line in myfile:
                line = line.rstrip()
                if student_list[0] in line:
                    changelist = line.split('\t')
                    password = input("Enter current password: ")
                    if password == changelist[10]:
                        changelist[10] = input("Enter new password: ")
                        new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                                    changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                                    changelist[8] + "\t" + changelist[9] + "\t" + changelist[10]
                        file_list.append(new_lines)
                    else:
                        print("Password Incorrect! Cannot change the password!")
                        check = 0
                else:
                    file_list.append(line)
        if check == 1:
            confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
            while confirm not in ('Y', 'y', 'N', 'n'):
                print("Invalid Input!")
                confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
            if confirm in ('Y', 'y'):
                myfile = open("data_file/student_file.txt", "w")
                for data in file_list:
                    myfile.write(data + "\n")
                myfile.close()
                print("--- Successfully modify record ---")
            else:
                print("--- Record not change ---")
        continue_opt = input("Do you want to continue modify other infomation? 'Y' to continue, 'N' back to Registered Student System: ")
        while continue_opt != 'Y' and continue_opt != 'y' and continue_opt != 'N' and continue_opt != 'n':
            print("Invalid Input!")
            continue_opt = input("Enter your selection again ( Y / N ): ")


def feedback_star_function(student_list):
    coach_file = open("data_file/coach_file.txt","r")
    sport_file = open("data_file/sport_file.txt", "r")
    feedback_file = open("data_file/coach_feedback.txt","a")
    coach = ""
    coach_id = ""
    file_list = []
    print("\n\t==========================\n"
          "\t We need your feedback!!!\n"
          "\t==========================\n"
          "We would like your feedback to improve our coaching quality.")
    for line in sport_file:
        line = line.rstrip()
        if student_list[6] in line:
            coach = line.split('\t')[3]
    print("Coach: " + coach)
    rate = input("Rate your coach on your training performance:\n\t[1] *---- (very poor performance)\n\t[2] **---\n\t"
                 "[3] ***--\n\t[4] ****-\n\t[5] ***** (excellect performance)\nEnter your rate (1-5): ")
    while rate not in ('1','2','3','4','5'):
        print("Rating not available!")
        rate = input("Enter your rate again (1-5): ")
    for line in coach_file:
        line = line.rstrip()
        if coach in line:
            coach_id = line.split('\t')[0]
            changelist = line.split('\t')
            change = round((float(line.split('\t')[9])+float(rate))/2,1)
            changelist[9] = str(change)
            new_lines = changelist[0] + "\t" + changelist[1] + "\t" + changelist[2] + "\t" + changelist[3] + "\t" + \
                        changelist[4] + "\t" + changelist[5] + "\t" + changelist[6] + "\t" + changelist[7] + "\t" + \
                        changelist[8] + "\t" + changelist[9] + "\t" + changelist[10] + "\t" + changelist[11] + "\t" + changelist[12]
            file_list.append(new_lines)
        else:
            file_list.append(line)
    feedback = input("\nGive a feedback to your coach:")
    confirm = input("Confirm to submit rating and feedback? 'Y' for YES,'N' for NO: ")
    while confirm not in ('Y', 'y', 'N', 'n'):
        print("Invalid Input!")
        confirm = input("Confirm to modify? 'Y' for Yes, 'N' for no: ")
    if confirm in ('Y','y'):
        coach_file = open("data_file/coach_file.txt", "w")
        for data in file_list:
            coach_file.write(data + "\n")
        coach_file.close()
        print("--- Thank You For Your Feedback ---")
        if feedback not in ("","-"):
            feedback_file.write(coach_id+"\t"+coach+"\t"+feedback+"\n")
            feedback_file.close
    else:
        print("--- Return to Registered Student System ---")


print("\n\t"
      "       ___________  ________ __________  __________ \n\t"
      "      /   ____   //   _____//   ______//  _____   /\n\t"
      "     /   /___/  //   /     /   /____  /  /____/  / \n\t"
      "    /   _   ___//   /      \_____   \/    __    /  \n\t"
      "   /   / \  \  /   /____ _______/   /   /  /   /   \n\t"
      "  /___/   \__\/________//__________/___/  /___/    ")
main_menu_function()
