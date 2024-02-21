st = []
for _ in range(int(input())):
    cmd = input()
    if cmd == "pwd":
        print('/',end='')
        for i in st:
            if i:
                print(i,end='/')
        print()
    else:
        path = cmd.split(' ')[1]
        dirs = path.split('/')
        if path[0]=='/':
            st.clear()
        for i in dirs:
            if i=="..":
                st.pop()
            else:
                st.append(i)

