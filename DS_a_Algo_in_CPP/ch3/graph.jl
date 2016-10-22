#using Gadfly
using PyPlot
f1 = open("joseplus_time")
f2 = open("joseplus_STL_time")
a = Float64[]
b = Float64[]
for ln in eachline(f1)
    n = parse(Float64, ln)
    push!(a, n)
end
for ln in eachline(f2)
    n = parse(Float64, ln)
    push!(b, n)
end
plot(a)
plot(b)
show()
