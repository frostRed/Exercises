using Gadfly
f = open("time")
a = Float64[]
for ln in eachline(f)
    n = prase(Float64, ln)
    push!(a, n)
end

