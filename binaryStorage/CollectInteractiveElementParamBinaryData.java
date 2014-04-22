package com.ankamagames.wakfu.client.binaryStorage;

public class CollectInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int UA;
    protected short czI;
    protected boolean czJ;
    protected int czK;
    protected dmv[] lDG;
    protected oj[] lDH;
    
    public CollectInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public short aeT()
    {
        int i = this.czI;
        return (short)i;
    }
    
    public boolean isLocked()
    {
        return this.czJ;
    }
    
    public int aeW()
    {
        return this.czK;
    }
    
    public dmv[] dca()
    {
        return this.lDG;
    }
    
    public oj[] dcb()
    {
        return this.lDH;
    }
    
    public void reset()
    {
        this.az = 0;
        this.UA = 0;
        this.czI = (short)0;
        this.czJ = false;
        this.czK = 0;
        this.lDG = null;
        this.lDH = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.UA = a.getInt();
        int i = a.getShort();
        this.czI = (short)i;
        this.czJ = a.readBoolean();
        this.czK = a.getInt();
        int i0 = a.getInt();
        this.lDG = new dmv[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.lDG[i1] = new dmv();
            this.lDG[i1].a(a);
            i1 = i1 + 1;
        }
        int i2 = a.getInt();
        this.lDH = new oj[i2];
        int i3 = 0;
        while(i3 < i2)
        {
            this.lDH[i3] = new oj();
            this.lDH[i3].a(a);
            i3 = i3 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDL.getId();
    }
}