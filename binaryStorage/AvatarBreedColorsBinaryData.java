package com.ankamagames.wakfu.client.binaryStorage;

public class AvatarBreedColorsBinaryData implements dEZ {
    protected int az;
    protected aGs[] bix;
    
    public AvatarBreedColorsBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public aGs[] Ax()
    {
        return this.bix;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bix = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getInt();
        this.bix = new aGs[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.bix[i0] = new aGs();
            this.bix[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFB.getId();
    }
}