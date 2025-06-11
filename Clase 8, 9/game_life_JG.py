def load_file():
    filepath = input("Enter the path of the file to load: ")
    file = open(filepath, 'r', encoding='utf-8')
    lines = file.readlines()
    file.close()
    return lines

def set_environment(raw_file):
    env = []
    for line in raw_file:
        line = line.strip()
        env.append([int(c) for c in line])
    return env
my_file = load_file()
env = set_environment(my_file)

def print_env(env):
    for row in env:
        for cell in row:
            if cell == 1:
                print('■', end='')

            else:
                print(' ', end='')
        print()

def check_neighbors(env,x,y):
    l1= [x-1, x, x + 1]
    l2= [y-1, y, y + 1]
    count = 0
    for i in l1:
        for j in l2:
            if x==i and y==j:
                continue
            if env[i][j] == 1:
                count+=1
    return count
print(check_neighbors(env,1,3))
print(env)
print_env(env)