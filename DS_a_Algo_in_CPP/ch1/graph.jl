#using Gadfly
using PyPlot
f = open("time2")
a = Float64[]
for ln in eachline(f)
    n = parse(Float64, ln)
    push!(a, n)
end
plot(a)
show()
