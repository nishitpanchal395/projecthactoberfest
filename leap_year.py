"""
********************************************************
 A year is leap year (366 days) if:
    i. Year is multiple of 400.
                OR
    ii. Year is multiple of 4 and not multiple of 100.
********************************************************
"""

year = int(input("Enter the year(yyyy): "))
if not(year % 400) or ( not (year%4) and (year%100)):
	print("Wow!", year, "is a leap year.")
else:
	print("Oops!", year, "is not a leap year.")
	
