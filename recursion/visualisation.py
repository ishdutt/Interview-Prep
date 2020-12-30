# Import Visualiser class from module visualiser
from visualiser.visualiser import Visualiser as vs

# Add decorator
# Decorator accepts optional arguments: ignore_args , show_argument_name, show_return_value and node_properties_kwargs
@vs(node_properties_kwargs={"shape":"record", "color":"#f57542", "style":"filled", "fillcolor":"grey"})
def fib(n,l,r,s,result):
    if(l==n and r==n):
        return result.append(s)
    else:
        if(l<n):
            fib(n,l+1,r,s+'(',result)
        if(r<l):
            fib(n,l,r+1,s+')',result)


def main():
    # Call function
    result = []
    fib(2,0,0,"",result)
    print(result)
    # Save recursion tree to a file
    vs.make_animation("fibonacci.gif", delay=2)


if __name__ == "__main__":
    main()