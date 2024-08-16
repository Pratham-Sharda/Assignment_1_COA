import matplotlib.pyplot as plt


sizes = [64, 128, 256, 512, 1024]


cpp_total_times_int = [0.135, 0.165, 0.275, 1.219, 10.111]
cpp_meat_times_int = [0.002, 0.019, 0.146, 1.091, 9.976]
python_total_times_int = [0.158, 0.493, 2.422, 16.630, 123.886]
python_meat_times_int  = [0.0201, 0.273, 2.20, 16.452, 123.57]

cpp_total_times_double = [0.138, 0.132, 0.253, 1.261, 16.422]
cpp_meat_times_double = [0.003, 0.016, 0.129, 1.134, 16.289]
python_total_times_double = [0.212, 0.342, 1.574, 13.629, 121.07]
python_meat_times_double  = [0.035, 0.195, 1.421, 13.465, 120.84]

cpp_user_times_double = [0,0,0,0,0]

python_user_times_double = [0,0,0,0.015,0.030]

cpp_sys_times_double = [0.138, 0.132, 0.253, 1.261, 16.422]

python_sys_times_double = [00.015,0.031,0.031,0.031,0.078]


cpp_user_times_int = [0,0,0.015,0,0]

python_user_times_int = [0,0,0,0.031,0.031]

cpp_sys_times_int = [0.015,0.016,0.015,0,0]

python_sys_times_int = [0.03,0,0.03,0.015,0.109]





plt.figure(figsize=(14, 7))


plt.subplot(1, 2, 1)
plt.plot(sizes, cpp_total_times_double, label='C++ Total execution Time double', marker='o', color='blue')
plt.plot(sizes, python_total_times_double, label='Python Total execution Time double ', marker='o', color='green')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Total execution Time (seconds)')
plt.title('Total execution Time vs. Matrix Size')
plt.legend()


plt.subplot(1, 2, 2)
plt.plot(sizes, cpp_meat_times_double, label='C++ Meat Time double ', marker='o', color='red')
plt.plot(sizes, python_meat_times_double, label='Python Meat Time double ', marker='o', color='orange')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Meat Time (seconds)')
plt.title('Meat Time vs. Matrix Size')
plt.legend()

plt.tight_layout()
plt.show()
