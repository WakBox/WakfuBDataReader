package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldBuildingVisualDefinitionBinaryData implements dEZ {
    protected int az;
    protected int aKe;
    protected ym[] aKf;
    
    public HavenWorldBuildingVisualDefinitionBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int nw()
    {
        return this.aKe;
    }
    
    public ym[] nx()
    {
        return this.aKf;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aKe = 0;
        this.aKf = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aKe = a.getInt();
        int i = a.getInt();
        this.aKf = new ym[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.aKf[i0] = new ym();
            this.aKf[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFs.getId();
    }
}