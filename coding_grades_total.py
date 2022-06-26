from __future__ import print_function
import re


def get_ok_num_perq(tresfile):
    file = open(tresfile,"r")
    cnt = 0
    f = file.read()
    lists = f.split("\n")
    
    for i in lists:
        if i:
            cnt += 1
    
    return cnt

total_coding_score = 0.0;

q_nums = [1, 2, 4, 5, 6]

for q_num in q_nums:
	pass_num = get_ok_num_perq("grades/Q%dres_.txt" % q_num)

	if q_num == 1:
		q1_score = pass_num * 1
		print("Q1:", pass_num, "/", 10, "passed | score:", q1_score)
		total_coding_score += q1_score
	elif q_num == 2:
		if pass_num <= 2:
			q2_score = pass_num * 6
		elif pass_num == 3:
			q2_score = 20
		print("Q2:", pass_num, "/", 3, "passed | score:", q2_score)
		total_coding_score += q2_score
	elif q_num == 4:
		q4_score = pass_num * 1.25
		print("Q4:", pass_num, "/", 16, "passed | score:", q4_score)
		total_coding_score += q4_score
	elif q_num == 5:
		q5_score = pass_num * 9.6
		print("Q5:", pass_num, "/", 5, "passed | score:", q5_score)
		total_coding_score += q5_score
	elif q_num == 6:
		if pass_num <= 18:
			q6_score = pass_num * 1
		elif pass_num == 19:
			q6_score = 20
		print("Q6:", pass_num, "/", 19, "passed | score:", q6_score)
		total_coding_score += q6_score
	
	else:
		raise ValueError('Wrong question number')


print("-----------------------------------------")
print("Your total score of coding section:", total_coding_score)
print("-----------------------------------------")
	

	
	
