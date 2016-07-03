% 将识别结果不对的图像的文件名的标签信息取反


clc
clear

imagefiles = dir('*.jpg');
nfiles = length(imagefiles);

for ii=1:nfiles
    currentfilename = imagefiles(ii).name;
    filename = strsplit(currentfilename, '.');
    fileid = strsplit(filename{1}, '-');
    rev = str2num(fileid{2});
    rev = abs(rev-1);
    newname = [fileid{1} '-' int2str(rev) '.' filename{2}];
  
    movefile(currentfilename,newname)

end

%copyfile('*.jpg','~/图片/tmp/')
%delete('*.jpg')
