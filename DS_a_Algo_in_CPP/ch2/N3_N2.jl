#using Gadfly
using PyPlot
f1 = open("time1")
f2 = open("time2")
f3 = open("time3")
f4 = open("time4")
a = Float64[]
b = Float64[]
c = Float64[]
d = Float64[]
for ln in eachline(f1)
    n = parse(Float64, ln)
    push!(a, n)
end
for ln in eachline(f2)
    n = parse(Float64, ln)
    push!(b, n)
end
for ln in eachline(f3)
    n = parse(Float64, ln)
    push!(c, n)
end
for ln in eachline(f4)
    n = parse(Float64, ln)
    push!(d, n)
end
plot(a)
plot(b)
#plot(c)
#plot(d)
show()
